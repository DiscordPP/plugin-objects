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

class Sticker {
  private:
    field<std::string> asset = std::string("");

  public:
    field<Snowflake> id;
    omittable_field<Snowflake> pack_id;
    field<std::string> name;
    nullable_field<std::string> description;
    field<std::string> tags;
    field<int> type;
    field<int> format_type;
    omittable_field<bool> available;
    omittable_field<Snowflake> guild_id;
    omittable_field<User> user;
    omittable_field<int> sort_value;

    NLOHMANN_DEFINE_FIELD_TYPE_INTRUSIVE(Sticker, {}, {}, id, pack_id, name,
                                         description, tags, asset, type,
                                         format_type, available, guild_id, user,
                                         sort_value)
};

class StickerItem {
  public:
    field<Snowflake> id;
    field<std::string> name;
    field<int> format_type;

    NLOHMANN_DEFINE_FIELD_TYPE_INTRUSIVE(StickerItem, {}, {}, id, name,
                                         format_type)
};

class StickerPack {
  public:
    field<Snowflake> id;
    field<std::vector<Sticker>> stickers;
    field<std::string> name;
    field<Snowflake> sku_id;
    omittable_field<Snowflake> cover_sticker_id;
    field<std::string> description;
    field<Snowflake> banner_asset_id;

    NLOHMANN_DEFINE_FIELD_TYPE_INTRUSIVE(StickerPack, {}, {}, id, stickers,
                                         name, sku_id, cover_sticker_id,
                                         description, banner_asset_id)
};
