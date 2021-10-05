//
// Created by Aidan on 8/27/2021.
//

// Howdy! This file contains unverified endpoints so they may need touching up.
// Sorry for the mess, I just don't have the time to verify everything by hand,
// especially with the volatile nature of a live service like Discord. If
// something doesn't work come swing by #🔚endpoints on the Discord++ server and
// someone'll help you out! If the endpoints work fine swing by that same
// channel with proof of credit for the @Endpoint Verifier role!

#ifndef OBJECT_BREAKOUTS
#error This header should only be included in plugin-objects.hh
#endif

using Options = json;

enum ButtonStyle : int {
    PRIMARY = 1,
    SECONDARY = 2,
    SUCCESS = 3,
    DANGER = 4,
    LINK = 5
};

enum ComponentType : int { ACTIONROW = 1, BUTTON = 2, SELECTMENU = 3 };

class Component {
  public:
    Component(ComponentType type, const std::optional<std::string> &customId,
              const std::optional<bool> &disabled,
              const std::optional<ButtonStyle> &style,
              const std::optional<std::string> &label,
              const std::optional<NewEmoji> &emoji,
              const std::optional<std::string> &url,
              const std::optional<std::vector<std::shared_ptr<Options>>> &options,
              const std::optional<std::string> &placeholder,
              const std::optional<int> &minValues,
              const std::optional<int> &maxValues,
              const std::optional<std::vector<std::shared_ptr<Component>>> &components)
        : type(type), custom_id(customId), disabled(disabled), style(style),
          label(label), emoji(emoji), url(url), options(options),
          placeholder(placeholder), min_values(minValues),
          max_values(maxValues), components(components) {}

    ComponentType type;
    std::optional<std::string> custom_id;
    std::optional<bool> disabled;
    std::optional<ButtonStyle> style;
    std::optional<std::string> label;
    std::optional<NewEmoji> emoji;
    std::optional<std::string> url;
    std::optional<std::vector<std::shared_ptr<Options>>> options;
    std::optional<std::string> placeholder;
    std::optional<int> min_values;
    std::optional<int> max_values;
    std::optional<std::vector<std::shared_ptr<Component>>> components;

    /*NLOHMANN_DEFINE_TYPE_INTRUSIVE(Component, type, custom_id, disabled,
       style, label, emoji, url, options, placeholder, min_values, max_values,
       components)*/
    friend void to_json(nlohmann::json &nlohmann_json_j,
                        const Component &nlohmann_json_t) {
        nlohmann_json_j["type"] = nlohmann_json_t.type;
        nlohmann_json_j["custom_id"] = nlohmann_json_t.custom_id;
        nlohmann_json_j["disabled"] = nlohmann_json_t.disabled;
        nlohmann_json_j["style"] = nlohmann_json_t.style;
        nlohmann_json_j["label"] = nlohmann_json_t.label;
        nlohmann_json_j["emoji"] = nlohmann_json_t.emoji;
        nlohmann_json_j["url"] = nlohmann_json_t.url;
        nlohmann_json_j["options"] = nlohmann_json_t.options;
        nlohmann_json_j["placeholder"] = nlohmann_json_t.placeholder;
        nlohmann_json_j["min_values"] = nlohmann_json_t.min_values;
        nlohmann_json_j["max_values"] = nlohmann_json_t.max_values;
        nlohmann_json_j["components"] = nlohmann_json_t.components;
    }
    friend void from_json(const nlohmann::json &nlohmann_json_j,
                          Component &nlohmann_json_t) {
        nlohmann_json_j.at("type").get_to(nlohmann_json_t.type);
        nlohmann_json_j.at("custom_id").get_to(nlohmann_json_t.custom_id);
        nlohmann_json_j.at("disabled").get_to(nlohmann_json_t.disabled);
        nlohmann_json_j.at("style").get_to(nlohmann_json_t.style);
        nlohmann_json_j.at("label").get_to(nlohmann_json_t.label);
        nlohmann_json_j.at("emoji").get_to(nlohmann_json_t.emoji);
        nlohmann_json_j.at("url").get_to(nlohmann_json_t.url);
        nlohmann_json_j.at("options").get_to(nlohmann_json_t.options);
        nlohmann_json_j.at("placeholder").get_to(nlohmann_json_t.placeholder);
        nlohmann_json_j.at("min_values").get_to(nlohmann_json_t.min_values);
        nlohmann_json_j.at("max_values").get_to(nlohmann_json_t.max_values);
        nlohmann_json_j.at("components").get_to(nlohmann_json_t.components);
    }
};
/*}
namespace nlohmann {
template<> struct adl_serializer<discordpp::Component> {
    static void to_json(json &nlohmann_json_j, const discordpp::Component &nlohmann_json_t) {
        NLOHMANN_JSON_EXPAND(NLOHMANN_JSON_PASTE(
            NLOHMANN_JSON_TO, type, custom_id, disabled, style, label, emoji,
            url, options, placeholder, min_values, max_values, components))
    }

    static void from_json(const json &nlohmann_json_j, discordpp::Component &nlohmann_json_t) {
        NLOHMANN_JSON_EXPAND(NLOHMANN_JSON_PASTE(
            NLOHMANN_JSON_FROM, type, custom_id, disabled, style, label, emoji,
            url, options, placeholder, min_values, max_values, components))
    }
};
} // namespace nlohmann
namespace discordpp {*/

class Button : public Component {
    using Component::components;
    using Component::max_values;
    using Component::min_values;
    using Component::options;
    using Component::placeholder;
    using Component::type;

  public:
    Button(const std::optional<std::string> &customId,
           const std::optional<bool> &disabled,
           const std::optional<ButtonStyle> &style,
           const std::optional<std::string> &label,
           const std::optional<NewEmoji> &emoji,
           const std::optional<std::string> &url,
           const std::optional<std::vector<std::shared_ptr<Component>>> &components)
        : Component(BUTTON, customId, disabled, style, label, emoji, url,
                    std::nullopt, std::nullopt, std::nullopt, std::nullopt,
                    std::nullopt) {}
};

class SelectMenu : public Component {
    using Component::emoji;
    using Component::label;
    using Component::style;
    using Component::url;

  public:
    SelectMenu(const std::optional<std::string> &customId,
               const std::optional<bool> &disabled,
               const std::vector<std::shared_ptr<Options>> &options,
               const std::optional<std::string> &placeholder,
               const std::optional<int> &minValues,
               const std::optional<int> &maxValues)
        : Component(SELECTMENU, customId, disabled, std::nullopt, std::nullopt,
                    std::nullopt, std::nullopt, options, placeholder, minValues,
                    maxValues, std::nullopt) {}

    std::vector<std::shared_ptr<Options>> &options = Component::options.value();
};

class ActionRow : public Component {
    using Component::custom_id;
    using Component::disabled;
    using Component::emoji;
    using Component::label;
    using Component::max_values;
    using Component::min_values;
    using Component::options;
    using Component::placeholder;
    using Component::style;
    using Component::url;

  public:
    ActionRow(const std::optional<std::vector<std::shared_ptr<Component>>> &components)
        : Component(ACTIONROW, std::nullopt, std::nullopt, std::nullopt,
                    std::nullopt, std::nullopt, std::nullopt, std::nullopt,
                    std::nullopt, std::nullopt, std::nullopt, components) {}
};