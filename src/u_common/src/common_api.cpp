/*
 * Copyright (C) default
 * DATE: 2021-09-18
 */

#include "common_api.h"
#include <tinyxml2.h>

namespace common {

CCommonApi::CCommonApi() {
    tinyxml2::XMLDocument doc;
}

CCommonApi::~CCommonApi() {
}

std::string CCommonApi::get_version() {
    return "v1.0.0";
}

}  // namespace common
