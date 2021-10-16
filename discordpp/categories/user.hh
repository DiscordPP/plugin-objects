//
// Created by Aidan on 4/20/2021.
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

class User {
  public:
    field<Snowflake> id;
    field<std::string> username;
    field<std::string> discriminator;
    nullable_field<std::string> avatar;
    omittable_field<bool> bot;
    omittable_field<bool> system;
    omittable_field<bool> mfa_enabled;
    nullable_omittable_field<std::string> banner;
    nullable_omittable_field<int> accent_color;
    omittable_field<std::string> locale;
    omittable_field<bool> verified;
    nullable_omittable_field<std::string> email;
    omittable_field<int> flags;
    omittable_field<int> premium_type;
    omittable_field<int> public_flags;

    NLOHMANN_DEFINE_FIELD_TYPE_INTRUSIVE(User, {}, {}, id, username, discriminator,
                                         avatar, bot, system, mfa_enabled,
                                         banner, accent_color, locale, verified,
                                         email, flags, premium_type,
                                         public_flags)
};