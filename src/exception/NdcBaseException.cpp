#include "index.hpp"
#include <string>

/**
 * アプリケーション向けの規定クラス
 */
NdcBaseException::NdcBaseException(const std::string &msg) { message = msg; }
char const *NdcBaseException::what() const noexcept { return message.c_str(); }
