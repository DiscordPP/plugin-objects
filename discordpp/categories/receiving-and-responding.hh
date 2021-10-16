//
// Created by Aidan on 8/28/2021.
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

class Interaction {
  public:
    field<Snowflake> id;
    field<Snowflake> application_id;
    field<InteractionType> type;
    omittable_field<InteractionData> data;
    omittable_field<Snowflake> guild_id;
    omittable_field<Snowflake> channel_id;
    omittable_field<GuildMember> member;
    omittable_field<User> user;
    field<std::string> token;
    field<int> version;
    omittable_field<Message> message;

    NLOHMANN_DEFINE_FIELD_TYPE_INTRUSIVE(Interaction, {}, {}, id,
                                         application_id, type, data, guild_id,
                                         channel_id, member, user, token,
                                         version, message)
};

class InteractionData {
  public:
    field<Snowflake> id;
    field<std::string> name;
    field<int> type;
    omittable_field<ResolvedData> resolved;
    omittable_field<std::vector<ApplicationCommandInteractionDataOption>>
        options;
    omittable_field<std::string> custom_id;
    omittable_field<int> component_type;
    omittable_field<std::vector<SelectOption>> values;
    omittable_field<Snowflake> target_id;

    NLOHMANN_DEFINE_FIELD_TYPE_INTRUSIVE(InteractionData, {}, {}, id, name,
                                         type, resolved, options, custom_id,
                                         component_type, values, target_id)
};

class ResolvedData {
  public:
    omittable_field<std::map<Snowflake, User>> users;
    omittable_field<std::map<Snowflake, GuildMember>> members;
    omittable_field<std::map<Snowflake, Role>> roles;
    omittable_field<std::map<Snowflake, Channel>> channels;
    omittable_field<std::map<Snowflake, Message>> messages;

    NLOHMANN_DEFINE_FIELD_TYPE_INTRUSIVE(ResolvedData, {}, {}, users, members,
                                         roles, channels, messages)
};

class MessageInteraction {
  public:
    field<Snowflake> id;
    field<InteractionType> type;
    field<std::string> name;
    field<User> user;

    NLOHMANN_DEFINE_FIELD_TYPE_INTRUSIVE(MessageInteraction, {}, {}, id, type,
                                         name, user)
};

class InteractionResponse {
  public:
    field<InteractionType> type;
    omittable_field<InteractionCallbackData> data;

    NLOHMANN_DEFINE_FIELD_TYPE_INTRUSIVE(InteractionResponse, {}, {}, type,
                                         data)
};

class InteractionCallbackData {
  public:
    omittable_field<bool> tts;
    omittable_field<std::string> content;
    omittable_field<std::vector<Embed>> embeds;
    omittable_field<AllowedMentions> allowed_mentions;
    omittable_field<InteractionCallbackDataFlags> flags;
    omittable_field<std::vector<Component>> components;

    NLOHMANN_DEFINE_FIELD_TYPE_INTRUSIVE(InteractionCallbackData, {}, {}, tts,
                                         content, embeds, allowed_mentions,
                                         flags, components)
};
