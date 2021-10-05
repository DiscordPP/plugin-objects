#pragma once

namespace discordpp {
template <class BASE> class PluginObjects : public BASE, virtual BotStruct {
};
#define OBJECT_BREAKOUTS
//#define Bot PluginObjects
#include "categories/application-commands.hh"
#include "categories/audit-log.hh"
#include "categories/channel.hh"
#include "categories/emoji.hh"
#include "categories/guild-template.hh"
#include "categories/guild.hh"
#include "categories/invite.hh"
#include "categories/message-components.hh"
#include "categories/receiving-and-responding.hh"
#include "categories/stage-instance.hh"
#include "categories/sticker.hh"
#include "categories/user.hh"
#include "categories/voice.hh"
#include "categories/webhook.hh"
//#undef Bot
#undef OBJECT_BREAKOUTS
} // namespace discordpp