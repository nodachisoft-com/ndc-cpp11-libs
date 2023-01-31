#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
  unsigned char r;
  unsigned char g;
  unsigned char b;
} ColorRGB;

typedef struct
{
  long height;
  long width;
  ColorRGB *data;
} ImageDataStruct;

class BitmapImage
{
private:
  // 定数
  static const int HEADERSIZE = 54;
  static const int PALLETSIZE = 1024;
  static const int MAX_IMAGE_MEMORY = (1024 * 1080) * (4 * 2); // @brief 4K レベルを上限

  // メタ情報部
  // TODO: MetaInfo 構造体に入れ込むべき
  unsigned char Bmp_headbuf[54];  /// @brief ヘッダを格納するための変数
  unsigned char Bmp_Pallet[1024]; /// @brief カラーパレットを格納

  char Bmp_type[2];                  /// @brief ファイルタイプ "BM"
  unsigned long Bmp_size;            /// @brief bmpファイルのサイズ (バイト)
  unsigned int Bmp_info_header_size; /// @brief 情報ヘッダのサイズ = 40
  unsigned int Bmp_header_size;      /// @brief ヘッダサイズ = 54
  long Bmp_height;                   /// @brief 高さ (ピクセル)
  long Bmp_width;                    /// @brief 幅   (ピクセル)
  unsigned short Bmp_planes;         /// @brief プレーン数 常に 1
  unsigned short Bmp_color;          /// @brief 色 (ビット)     24
  long Bmp_comp;                     /// @brief 圧縮方法         0
  long Bmp_image_size;               /// @brief 画像部分のファイルサイズ (バイト)
  long Bmp_xppm;                     /// @brief 水平解像度 (ppm)
  long Bmp_yppm;                     /// @brief 垂直解像度 (ppm)

  ImageDataStruct imgp; /// 画像データ本体

public:
  /// コンストラクタ
  BitmapImage(const char *filename);
  BitmapImage(const int width, const int height);

  /// デストラクタ
  ~BitmapImage();

  // 操作
  void ReadBmp(const char *filename);
  void WriteBmp(const char *filename);
  void PrintBmpInfo(const char *filename);

  // TODO: set、get で色情報の書き込み、読み取りができるようにする
};
