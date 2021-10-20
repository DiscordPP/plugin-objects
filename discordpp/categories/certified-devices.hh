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

class Device {
  public:
    field<DeviceType> type;
    field<std::string> id;
    field<Vendor> vendor;
    field<Model> model;
    field<std::vector<std::string>> related;
    omittable_field<bool> echo_cancellation;
    omittable_field<bool> noise_suppression;
    omittable_field<bool> automatic_gain_control;
    omittable_field<bool> hardware_mute;

    NLOHMANN_DEFINE_FIELD_TYPE_INTRUSIVE(Device, {}, {}, type, id, vendor,
                                         model, related, echo_cancellation,
                                         noise_suppression,
                                         automatic_gain_control, hardware_mute)
};

class Vendor {
  public:
    field<std::string> name;
    field<std::string> url;

    NLOHMANN_DEFINE_FIELD_TYPE_INTRUSIVE(Vendor, {}, {}, name, url)
};

class Model {
  public:
    field<std::string> name;
    field<std::string> url;

    NLOHMANN_DEFINE_FIELD_TYPE_INTRUSIVE(Model, {}, {}, name, url)
};
