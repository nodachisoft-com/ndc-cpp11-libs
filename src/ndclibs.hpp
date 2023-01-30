/**
 * NDC-LIBS の公開機能を提供するヘッダーを include する。
 * ライブラリのユーザは当該ヘッダーを指定すれば、配下の各機能が利用可能となる
 */
#pragma once

// 標準ライブラリ系で必要なものをまとめて記述
#include <iostream>

// 各機能へのヘッダーを記述
#include "exception/index.hpp"
#include "random/index.hpp"
#include "scalable_byte_array/index.hpp"
#include "serializable/index.hpp"
