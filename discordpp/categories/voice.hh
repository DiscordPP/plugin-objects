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

class VoiceState {
  public:
    omittable_field<Snowflake> guild_id;
    nullable_field<Snowflake> channel_id;
    field<Snowflake> user_id;
    omittable_field<GuildMember> member;
    field<std::string> session_id;
    field<bool> deaf;
    field<bool> mute;
    field<bool> self_deaf;
    field<bool> self_mute;
    omittable_field<bool> self_stream;
    field<bool> self_video;
    field<bool> suppress;
    nullable_field<Timestamp> request_to_speak_timestamp;

    NLOHMANN_DEFINE_FIELD_TYPE_INTRUSIVE(VoiceState, {}, {}, guild_id,
                                         channel_id, user_id, member,
                                         session_id, deaf, mute, self_deaf,
                                         self_mute, self_stream, self_video,
                                         suppress, request_to_speak_timestamp)
};

class VoiceRegion {
  public:
    field<std::string> id;
    field<std::string> name;
    field<bool> optimal;
    field<bool> deprecated;
    field<bool> custom;

    NLOHMANN_DEFINE_FIELD_TYPE_INTRUSIVE(VoiceRegion, {}, {}, id, name, optimal,
                                         deprecated, custom)
};
