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

class Webhook {
  public:
    field<Snowflake> id;
    field<int> type;
    nullable_omittable_field<Snowflake> guild_id;
    nullable_field<Snowflake> channel_id;
    omittable_field<User> user;
    nullable_field<std::string> name;
    nullable_field<std::string> avatar;
    omittable_field<std::string> token;
    nullable_field<Snowflake> application_id;
    omittable_field<Guild> source_guild;
    omittable_field<Channel> source_channel;
    omittable_field<std::string> url;

    NLOHMANN_DEFINE_FIELD_TYPE_INTRUSIVE(Webhook, {}, {}, id, type, guild_id,
                                         channel_id, user, name, avatar, token,
                                         application_id, source_guild,
                                         source_channel, url)
};
