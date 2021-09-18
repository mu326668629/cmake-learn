#include <iostream>
#include <common_api.h>
#include <api.h>

int main()
{
    common::CCommonApi obj;
    std::cout<<"hello world version="<<obj.get_version()<<API_VERSION<<std::endl;
    return 0;
}