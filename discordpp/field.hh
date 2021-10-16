//
// Created by Aidan on 10/13/2021.
//

#pragma once

struct nulled_t {};
inline static const nulled_t nulled;
struct omitted_t {};
inline static const omitted_t omitted;
struct uninitialized_t {};
inline static const uninitialized_t uninitialized;

template <typename T> class field {
  protected:
    enum state { uninitialized_e, present_e, omitted_e, nulled_e };

    field(std::unique_ptr<T> t, state s) : t_(std::move(t)), s_(s) {}

    std::unique_ptr<T> t_;
    state s_;

  public:
    field() : t_(nullptr), s_(uninitialized_e) {}
    field(uninitialized_t) : t_(nullptr), s_(uninitialized_e) {}
    field(const T &t) : t_(std::make_unique<T>(t)), s_(present_e) {}
    field(const field<T> &f) : t_(std::make_unique<T>(*f.t_)), s_(f.s_) {}
    /*field(std::initializer_list<T> &t)
        : t_(std::make_unique<T>(*t.begin())), s_(present_e) {
        assert(t.size() == 1);
    }*/

    operator bool() const { return s_ == present_e; }
    constexpr T operator->() { return **this; }
    constexpr T operator*() {
        if (s_ != present_e) {
            throw std::logic_error("This field is not present.");
        }
        return &*t_;
    }
    field<T> &operator=(const T &t) {
        t_.reset(new T(t));
        s_ = present_e;
        return *this;
    }
    field<T> &operator=(const field<T> &f) {
        t_.reset(new T(*f.t_));
        s_ = present_e;
        return *this;
    }

    [[nodiscard]] bool is_uninitialized() const { return s_ == uninitialized_e; }
    [[nodiscard]] bool is_present() const { return s_ == present_e; }
    [[nodiscard]] bool is_omitted() const { return s_ == omitted_e; }
    [[nodiscard]] bool is_null() const { return s_ == nulled_e; }

    friend void to_json(nlohmann::json &j, const field<T> &f) {
        switch (f.s_) {
        case uninitialized_e:
            throw std::logic_error(
                "You can't convert an uninitialized field to JSON");
            break;
        case present_e:
            // if constexpr (std::is_enum_v<T>) {
            //     j = static_cast<typename
            //     std::underlying_type<T>::type>(*f.t_);
            // } else {
            j = *f.t_;
            //}
            break;
        case nulled_e:
            j = nullptr;
            break;
        case omitted_e:
            throw std::logic_error(
                "You can't convert an omitted field to JSON");
            break;
        }
    }
    friend void from_json(const nlohmann::json &j, field<T> &f) {
        if (j.is_null()) {
            f.t_ = nullptr;
            f.s_ = nulled_e;
        } else {
            f.t_ = std::make_unique<T>(j.get<T>());
            f.s_ = present_e;
        }
    }
};
template <typename T> class nullable_field : public field<T> {
  public:
    nullable_field() : field<T>(nullptr, field<T>::uninitialized_e) {}
    nullable_field(const T &t) : field<T>(t) {}
    nullable_field(uninitialized_t)
        : field<T>(nullptr, field<T>::uninitialized_e) {}
    nullable_field(nulled_t) : field<T>(nullptr, field<T>::nulled_e) {}
    nullable_field(std::nullptr_t) : field<T>(nullptr, field<T>::nulled_e) {}
    virtual nullable_field &operator=(nulled_t) {
        field<T>::t_ = nullptr;
        field<T>::s_ = field<T>::nulled_e;
        return *this;
    }
    virtual nullable_field &operator=(std::nullptr_t) {
        field<T>::t_ = nullptr;
        field<T>::s_ = field<T>::nulled_e;
        return *this;
    }
};
template <typename T> class omittable_field : public field<T> {
  public:
    omittable_field() : field<T>(nullptr, field<T>::omitted_e) {}
    omittable_field(const T &t) : field<T>(t) {}
    omittable_field(uninitialized_t)
        : field<T>(nullptr, field<T>::uninitialized_e) {}
    omittable_field(omitted_t) : field<T>(nullptr, field<T>::omitted_e) {}
    virtual omittable_field &operator=(omitted_t) {
        field<T>::t_ = nullptr;
        field<T>::s_ = field<T>::omitted_e;
        return *this;
    }
};
template <typename T> class nullable_omittable_field : public field<T> {
  public:
    nullable_omittable_field() : field<T>(nullptr, field<T>::omitted_e) {}
    nullable_omittable_field(const T &t) : field<T>(t) {}
    nullable_omittable_field(uninitialized_t)
        : field<T>(nullptr, field<T>::uninitialized_e) {}
    nullable_omittable_field(nulled_t)
        : field<T>(nullptr, field<T>::nulled_e) {}
    nullable_omittable_field(std::nullptr_t)
        : field<T>(nullptr, field<T>::nulled_e) {}
    nullable_omittable_field(omitted_t)
        : field<T>(nullptr, field<T>::omitted_e) {}
    virtual nullable_omittable_field &operator=(nulled_t) {
        field<T>::t_ = nullptr;
        field<T>::s_ = field<T>::nulled_e;
        return *this;
    }
    virtual nullable_omittable_field &operator=(std::nullptr_t) {
        field<T>::t_ = nullptr;
        field<T>::s_ = field<T>::nulled_e;
        return *this;
    }
    virtual nullable_omittable_field &operator=(omitted_t) {
        field<T>::t_ = nullptr;
        field<T>::s_ = field<T>::omitted_e;
        return *this;
    }
};

#define NLOHMANN_JSON_TO_FIELD(v1)                                             \
    if (!nlohmann_json_t.v1.is_omitted()) {                                    \
        NLOHMANN_JSON_TO(v1)                                                   \
    }
#define NLOHMANN_JSON_FROM_FIELD(v1) NLOHMANN_JSON_FROM(v1)

#define NLOHMANN_DEFINE_FIELD_TYPE_INTRUSIVE(Type, ToExtra, FromExtra, ...)    \
    friend void to_json(nlohmann::json &nlohmann_json_j,                       \
                        const Type &nlohmann_json_t) {                         \
        auto &j = nlohmann_json_j;                                             \
        const auto &t = nlohmann_json_t;                                       \
        ToExtra;                                                               \
        NLOHMANN_JSON_EXPAND(                                                  \
            NLOHMANN_JSON_PASTE(NLOHMANN_JSON_TO_FIELD, __VA_ARGS__));         \
    }                                                                          \
    friend void from_json(const nlohmann::json &nlohmann_json_j,               \
                          Type &nlohmann_json_t) {                             \
        const auto &j = nlohmann_json_j;                                             \
        auto &t = nlohmann_json_t;                                       \
        FromExtra;                                                             \
        NLOHMANN_JSON_EXPAND(                                                  \
            NLOHMANN_JSON_PASTE(NLOHMANN_JSON_FROM_FIELD, __VA_ARGS__));       \
    }

#define NLOHMANN_DEFINE_FIELD_TYPE_NON_INTRUSIVE(Type, ToExtra, FromExtra,     \
                                                 ...)                          \
    inline void to_json(nlohmann::json &nlohmann_json_j,                       \
                        const Type &nlohmann_json_t) {                         \
        ToExtra;                                                               \
        NLOHMANN_JSON_EXPAND(                                                  \
            NLOHMANN_JSON_PASTE(NLOHMANN_JSON_TO_FIELD, __VA_ARGS__));         \
    }                                                                          \
    inline void from_json(const nlohmann::json &nlohmann_json_j,               \
                          Type &nlohmann_json_t) {                             \
        FromExtra;                                                             \
        NLOHMANN_JSON_EXPAND(                                                  \
            NLOHMANN_JSON_PASTE(NLOHMANN_JSON_FROM_FIELD, __VA_ARGS__));       \
    }
