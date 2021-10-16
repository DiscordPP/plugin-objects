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

class Application {
  public:
    Application() = default;

    field<Snowflake> id;
    field<std::string> name;
    nullable_field<std::string> icon;
    field<std::string> description;
    omittable_field<std::vector<std::string>> rpc_origins;
    field<bool> bot_public;
    field<bool> bot_require_code_grant;
    omittable_field<std::string> terms_of_service_url;
    omittable_field<std::string> privacy_policy_url;
    omittable_field<User> owner;
    field<std::string> summary;
    field<std::string> verify_key;
    nullable_field<Team> team;
    omittable_field<Snowflake> guild_id;
    omittable_field<Snowflake> primary_sku_id;
    omittable_field<std::string> slug;
    omittable_field<std::string> cover_image;
    omittable_field<ApplicationFlags> flags;

    NLOHMANN_DEFINE_FIELD_TYPE_INTRUSIVE(
        Application, {}, {}, id, name, icon, description, rpc_origins,
        bot_public, bot_require_code_grant, terms_of_service_url,
        privacy_policy_url, owner, summary, verify_key, team, guild_id,
        primary_sku_id, slug, cover_image, flags)
};