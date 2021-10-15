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

#include "../field.hh"

using SelectOptions = json;

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
    Component() = default;

    Component(field<ComponentType> type, omittable_field<std::string> customId,
              omittable_field<bool> disabled,
              omittable_field<ButtonStyle> style,
              omittable_field<std::string> label, omittable_field<Emoji> emoji,
              omittable_field<std::string> url,
              omittable_field<std::vector<SelectOptions>> options,
              omittable_field<std::string> placeholder,
              omittable_field<int> minValues, omittable_field<int> maxValues,
              omittable_field<std::vector<Component>> components)
        : type(std::move(type)), custom_id(std::move(customId)),
          disabled(std::move(disabled)), style(std::move(style)),
          label(std::move(label)), emoji(std::move(emoji)), url(std::move(url)),
          options(std::move(options)), placeholder(std::move(placeholder)),
          min_values(std::move(minValues)), max_values(std::move(maxValues)),
          components(std::move(components)) {}

    field<ComponentType> type;
    omittable_field<std::string> custom_id;
    omittable_field<bool> disabled;
    omittable_field<ButtonStyle> style;
    omittable_field<std::string> label;
    omittable_field<Emoji> emoji;
    omittable_field<std::string> url;
    omittable_field<std::vector<SelectOptions>> options;
    omittable_field<std::string> placeholder;
    omittable_field<int> min_values;
    omittable_field<int> max_values;
    omittable_field<std::vector<Component>> components;

    NLOHMANN_DEFINE_FIELD_TYPE_INTRUSIVE(Component, type, custom_id, disabled,
                                         style, label, emoji, url, options,
                                         placeholder, min_values, max_values,
                                         components)
};

class Button : public Component {
    using Component::components;
    using Component::max_values;
    using Component::min_values;
    using Component::options;
    using Component::placeholder;
    using Component::type;

  public:
    Button(omittable_field<std::string> customId,
           omittable_field<bool> disabled, omittable_field<ButtonStyle> style,
           omittable_field<std::string> label, omittable_field<Emoji> emoji,
           omittable_field<std::string> url,
           omittable_field<std::vector<Component>> components)
        : Component(BUTTON, customId, disabled, style, label, emoji, url,
                    omitted, omitted, omitted, omitted, omitted) {}
};

class SelectMenu : public Component {
    using Component::emoji;
    using Component::label;
    using Component::style;
    using Component::url;

  public:
    SelectMenu(omittable_field<std::string> customId,
               omittable_field<bool> disabled,
               std::vector<SelectOptions> options,
               omittable_field<std::string> placeholder,
               omittable_field<int> minValues, omittable_field<int> maxValues)
        : Component(SELECTMENU, customId, disabled, omitted, omitted, omitted,
                    omitted, options, placeholder, minValues, maxValues,
                    omitted) {}
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
    ActionRow(omittable_field<std::vector<Component>> components)
        : Component(ACTIONROW, omitted, omitted, omitted, omitted, omitted,
                    omitted, omitted, omitted, omitted, omitted, components) {}
};