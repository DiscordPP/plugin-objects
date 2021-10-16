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

class User;

class Emoji {
  public:
    nullable_field<Snowflake> id;
    nullable_field<std::string> name;
    omittable_field<std::vector<Snowflake>> roles;
    omittable_field<User> user;
    omittable_field<bool> require_colons;
    omittable_field<bool> managed;
    omittable_field<bool> animated;
    omittable_field<bool> available;

    NLOHMANN_DEFINE_FIELD_TYPE_INTRUSIVE(Emoji, {}, {}, id, name, roles, user,
                                         require_colons, managed, animated,
                                         available)
};