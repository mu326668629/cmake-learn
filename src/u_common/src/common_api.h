/*
 * Copyright (C) default
 * DATE: 2021-09-18
 */

#ifndef __COMMON_API_H__
#define __COMMON_API_H__

#include <string>

namespace common {

class CCommonApi {
 public:
  CCommonApi();
  ~CCommonApi();
  std::string get_version();

 private:
};

}  // namespace common
#endif
