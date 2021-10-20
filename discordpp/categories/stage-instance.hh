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

class StageInstance {
  public:
    field<Snowflake> id;
    field<Snowflake> guild_id;
    field<Snowflake> channel_id;
    field<std::string> topic;
    field<int> privacy_level;
    field<bool> discoverable_disabled;

    NLOHMANN_DEFINE_FIELD_TYPE_INTRUSIVE(StageInstance, {}, {}, id, guild_id,
                                         channel_id, topic, privacy_level,
                                         discoverable_disabled)
};
