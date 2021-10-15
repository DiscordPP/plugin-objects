//
// Created by Aidan on 3/11/2021.
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

class Message {
  public:
    Message() = default;

    enum Type : int {
        DEFAULT = 0,
        RECIPIENT_ADD = 1,
        RECIPIENT_REMOVE = 2,
        CALL = 3,
        CHANNEL_NAME_CHANGE = 4,
        CHANNEL_ICON_CHANGE = 5,
        CHANNEL_PINNED_MESSAGE = 6,
        GUILD_MEMBER_JOIN = 7,
        USER_PREMIUM_GUILD_SUBSCRIPTION = 8,
        USER_PREMIUM_GUILD_SUBSCRIPTION_TIER_1 = 9,
        USER_PREMIUM_GUILD_SUBSCRIPTION_TIER_2 = 10,
        USER_PREMIUM_GUILD_SUBSCRIPTION_TIER_3 = 11,
        CHANNEL_FOLLOW_ADD = 12,
        GUILD_DISCOVERY_DISQUALIFIED = 14,
        GUILD_DISCOVERY_REQUALIFIED = 15,
        GUILD_DISCOVERY_GRACE_PERIOD_INITIAL_WARNING = 16,
        GUILD_DISCOVERY_GRACE_PERIOD_FINAL_WARNING = 17,
        THREAD_CREATED = 18,
        REPLY = 19,
        CHAT_INPUT_COMMAND = 20,
        THREAD_STARTER_MESSAGE = 21,
        GUILD_INVITE_REMINDER = 22,
        CONTEXT_MENU_COMMAND = 23
    };

    enum Flag : int {
        CROSSPOSTED = 1 << 0,
        IS_CROSSPOST = 1 << 1,
        SUPPRESS_EMBEDS = 1 << 2,
        SOURCE_MESSAGE_DELETED = 1 << 3,
        URGENT = 1 << 4,
        HAS_THREAD = 1 << 5,
        EPHEMERAL = 1 << 6,
        LOADING = 1 << 7
    };

    field<Snowflake> id;
    field<Snowflake> channel_id;
    omittable_field<Snowflake> guild_id;
    field<User> author;
    omittable_field<GuildMember> member;
    field<std::string> content;
    field<Timestamp> timestamp;
    field<Timestamp> edited_timestamp;
    field<bool> tts;
    field<bool> mention_everyone;
    field<std::vector<User>> mentions;
    field<std::vector<Snowflake>> mention_roles;
    omittable_field<std::vector<ChannelMention>> mention_channels;
    field<std::vector<Attachment>> attachments;
    field<std::vector<Embed>> embeds;
    omittable_field<std::vector<Reaction>> reactions;
    omittable_field<std::variant<int, std::string>> nonce;
    field<bool> pinned;
    omittable_field<Snowflake> webhook_id;
    field<Type> type;
    omittable_field<MessageActivity> activity;
    omittable_field<Application> application;
    omittable_field<Snowflake> application_id;
    nullable_omittable_field<MessageReference> message_reference;
    omittable_field<Flag> flags;
    omittable_field<MessageReference> referenced_message;
    omittable_field<MessageInteraction> interaction;
    omittable_field<Channel> thread;
    omittable_field<std::vector<Component>> components;
    omittable_field<std::vector<StickerItem>> sticker_items;

    NLOHMANN_DEFINE_FIELD_TYPE_INTRUSIVE(
        Message, id, channel_id, guild_id, author, member, content, timestamp,
        edited_timestamp, tts, mention_everyone, mentions, mention_roles,
        mention_channels, attachments, embeds, reactions, nonce, pinned,
        webhook_id, type, activity, application, application_id,
        message_reference, flags, referenced_message, interaction, thread,
        components, sticker_items)
};