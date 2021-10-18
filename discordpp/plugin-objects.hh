#pragma once

#include <discordpp/botStruct.hh>
#include <discordpp/enum.hh>

#include <nlohmann/json.hpp>

namespace discordpp {
using json = nlohmann::json;

template <class BASE> class PluginObjects : public BASE, virtual BotStruct {
};

template <typename T>
inline handleEvent objectify(const std::function<void(const T t)>& func){
    return [func](const json j){
        func(j.get<T>());
    };
}
template <typename T>
inline handleRead objectify(const std::function<void(const bool error, const T t)>& func){
    return [func](const bool e, const json j){
        func(e, j.get<T>());
    };
}

#define OBJECT_BREAKOUTS
//#define Bot PluginObjects
/* This space intentionally left blank */
using Timestamp = std::string;
/* This space intentionally left blank */
#include "categories/application-commands_fwd.hh"
#include "categories/application_fwd.hh"
#include "categories/audit-log_fwd.hh"
#include "categories/certified-devices_fwd.hh"
#include "categories/channel_fwd.hh"
#include "categories/emoji_fwd.hh"
#include "categories/guild-template_fwd.hh"
#include "categories/guild_fwd.hh"
#include "categories/invite_fwd.hh"
#include "categories/message-components_fwd.hh"
#include "categories/oauth2_fwd.hh"
#include "categories/permissions_fwd.hh"
#include "categories/receiving-and-responding_fwd.hh"
#include "categories/stage-instance_fwd.hh"
#include "categories/sticker_fwd.hh"
#include "categories/teams_fwd.hh"
#include "categories/user_fwd.hh"
#include "categories/voice_fwd.hh"
#include "categories/webhook_fwd.hh"
/* This space intentionally left blank */
#include "categories/gateway_fwd.hh"
/* This space intentionally left blank */
#include "categories/application-commands.hh"
#include "categories/application.hh"
#include "categories/audit-log.hh"
#include "categories/certified-devices.hh"
#include "categories/channel.hh"
#include "categories/emoji.hh"
#include "categories/gateway.hh"
#include "categories/guild-template.hh"
#include "categories/guild.hh"
#include "categories/invite.hh"
#include "categories/message-components.hh"
#include "categories/oauth2.hh"
#include "categories/permissions.hh"
#include "categories/stage-instance.hh"
#include "categories/sticker.hh"
#include "categories/teams.hh"
#include "categories/user.hh"
#include "categories/voice.hh"
#include "categories/webhook.hh"
/* This space intentionally left blank */
#include "categories/receiving-and-responding.hh"
//#undef Bot
#undef OBJECT_BREAKOUTS
} // namespace discordpp