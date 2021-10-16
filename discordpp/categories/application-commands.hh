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

class ApplicationCommand {
  public:
    field<Snowflake> id;
    omittable_field<ApplicationCommandType> type;
    field<Snowflake> application_id;
    omittable_field<Snowflake> guild_id;
    field<std::string> name;
    field<std::string> description;
    omittable_field<std::vector<ApplicationCommandOption>> options;
    omittable_field<bool> default_permission;
    field<Snowflake> version;

    NLOHMANN_DEFINE_FIELD_TYPE_INTRUSIVE(ApplicationCommand, {}, {}, id, type,
                                         application_id, guild_id, name,
                                         description, options,
                                         default_permission, version);
};

class ApplicationCommandOption {
  public:
    field<ApplicationCommandOptionType> type;
    field<std::string> name;
    field<std::string> description;
    omittable_field<bool> required;
    omittable_field<std::vector<ApplicationCommandOptionChoice>> choices;
    omittable_field<std::vector<ApplicationCommandOption>> options;
    omittable_field<MessageType> channel_types;

    NLOHMANN_DEFINE_FIELD_TYPE_INTRUSIVE(ApplicationCommandOption, {}, {}, type,
                                         name, description, required, choices,
                                         options, channel_types);
};

class ApplicationCommandOptionChoice {
  public:
    field<std::string> name;
    field<std::variant<int, double, std::string>> value;

    NLOHMANN_DEFINE_FIELD_TYPE_INTRUSIVE(ApplicationCommandOptionChoice, {}, {},
                                         name, value);
};

class ApplicationCommandInteractionDataOption {
  public:
    field<std::string> name;
    field<ApplicationCommandOptionType> type;
    omittable_field<json> value;
    omittable_field<std::vector<ApplicationCommandInteractionDataOption>>
        options;

    NLOHMANN_DEFINE_FIELD_TYPE_INTRUSIVE(
        ApplicationCommandInteractionDataOption,
        {
            if (t.value.is_omitted() && t.options.is_omitted()) {
                throw std::logic_error(
                    "Either \"value\" or \"options\" must be present to "
                    "serialize an ApplicationCommandInteractionDataOption");
            }
        },
        {}, name, type, value, options);
};

class GuildApplicationCommandPermissions {
  public:
    field<Snowflake> id;
    field<Snowflake> application_id;
    field<Snowflake> guild_id;
    field<std::vector<ApplicationCommandPermission>> permissions;

    NLOHMANN_DEFINE_FIELD_TYPE_INTRUSIVE(GuildApplicationCommandPermissions, {},
                                         {}, id, application_id, guild_id,
                                         permissions);
};

class ApplicationCommandPermission {
  public:
    field<Snowflake> id;
    field<ApplicationCommandPermissionType> type;
    field<bool> permission;

    NLOHMANN_DEFINE_FIELD_TYPE_INTRUSIVE(ApplicationCommandPermission, {}, {},
                                         id, type, permission);
};
