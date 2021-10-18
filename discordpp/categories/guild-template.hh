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

class GuildTemplate {
  public:
    field<std::string> code;
    field<std::string> name;
    nullable_field<std::string> description;
    field<int> usage_count;
    field<Snowflake> creator_id;
    field<User> creator;
    field<Timestamp> created_at;
    field<Timestamp> updated_at;
    field<Snowflake> source_guild_id;
    field<Guild> serialized_source_guild;
    nullable_field<bool> is_dirty;

    NLOHMANN_DEFINE_FIELD_TYPE_INTRUSIVE(GuildTemplate, {}, {}, code, name,
                                         description, usage_count, creator_id,
                                         creator, created_at, updated_at,
                                         source_guild_id,
                                         serialized_source_guild, is_dirty)
};
