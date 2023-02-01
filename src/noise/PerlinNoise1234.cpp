#include "PerlinNoise1234.hpp"

// #define FADE(t) (t * t * t * (t * (t * 6 - 15) + 10))
float PerlinNoise1234::FADE(float t)
{
  return (t * t * t * (t * (t * 6 - 15) + 10));
}

// #define FASTFLOOR(x) (((int)(x) < (x)) ? ((int)x) : ((int)x - 1))
int PerlinNoise1234::FASTFLOOR(float x)
{
  return (((int)(x) < (x)) ? ((int)x) : ((int)x - 1));
}

float PerlinNoise1234::LERP(float t, float a, float b)
{
  return ((a) + (t) * ((b) - (a)));
}
// #define LERP(t, a, b) ((a) + (t) * ((b) - (a)))

unsigned char PerlinNoise1234::perm[] = {151, 160, 137, 91, 90, 15,
                                         131, 13, 201, 95, 96, 53, 194, 233, 7, 225, 140, 36, 103, 30, 69, 142, 8, 99, 37, 240, 21, 10, 23,
                                         190, 6, 148, 247, 120, 234, 75, 0, 26, 197, 62, 94, 252, 219, 203, 117, 35, 11, 32, 57, 177, 33,
                                         88, 237, 149, 56, 87, 174, 20, 125, 136, 171, 168, 68, 175, 74, 165, 71, 134, 139, 48, 27, 166,
                                         77, 146, 158, 231, 83, 111, 229, 122, 60, 211, 133, 230, 220, 105, 92, 41, 55, 46, 245, 40, 244,
                                         102, 143, 54, 65, 25, 63, 161, 1, 216, 80, 73, 209, 76, 132, 187, 208, 89, 18, 169, 200, 196,
                                         135, 130, 116, 188, 159, 86, 164, 100, 109, 198, 173, 186, 3, 64, 52, 217, 226, 250, 124, 123,
                                         5, 202, 38, 147, 118, 126, 255, 82, 85, 212, 207, 206, 59, 227, 47, 16, 58, 17, 182, 189, 28, 42,
                                         223, 183, 170, 213, 119, 248, 152, 2, 44, 154, 163, 70, 221, 153, 101, 155, 167, 43, 172, 9,
                                         129, 22, 39, 253, 19, 98, 108, 110, 79, 113, 224, 232, 178, 185, 112, 104, 218, 246, 97, 228,
                                         251, 34, 242, 193, 238, 210, 144, 12, 191, 179, 162, 241, 81, 51, 145, 235, 249, 14, 239, 107,
                                         49, 192, 214, 31, 181, 199, 106, 157, 184, 84, 204, 176, 115, 121, 50, 45, 127, 4, 150, 254,
                                         138, 236, 205, 93, 222, 114, 67, 29, 24, 72, 243, 141, 128, 195, 78, 66, 215, 61, 156, 180,
                                         151, 160, 137, 91, 90, 15,
                                         131, 13, 201, 95, 96, 53, 194, 233, 7, 225, 140, 36, 103, 30, 69, 142, 8, 99, 37, 240, 21, 10, 23,
                                         190, 6, 148, 247, 120, 234, 75, 0, 26, 197, 62, 94, 252, 219, 203, 117, 35, 11, 32, 57, 177, 33,
                                         88, 237, 149, 56, 87, 174, 20, 125, 136, 171, 168, 68, 175, 74, 165, 71, 134, 139, 48, 27, 166,
                                         77, 146, 158, 231, 83, 111, 229, 122, 60, 211, 133, 230, 220, 105, 92, 41, 55, 46, 245, 40, 244,
                                         102, 143, 54, 65, 25, 63, 161, 1, 216, 80, 73, 209, 76, 132, 187, 208, 89, 18, 169, 200, 196,
                                         135, 130, 116, 188, 159, 86, 164, 100, 109, 198, 173, 186, 3, 64, 52, 217, 226, 250, 124, 123,
                                         5, 202, 38, 147, 118, 126, 255, 82, 85, 212, 207, 206, 59, 227, 47, 16, 58, 17, 182, 189, 28, 42,
                                         223, 183, 170, 213, 119, 248, 152, 2, 44, 154, 163, 70, 221, 153, 101, 155, 167, 43, 172, 9,
                                         129, 22, 39, 253, 19, 98, 108, 110, 79, 113, 224, 232, 178, 185, 112, 104, 218, 246, 97, 228,
                                         251, 34, 242, 193, 238, 210, 144, 12, 191, 179, 162, 241, 81, 51, 145, 235, 249, 14, 239, 107,
                                         49, 192, 214, 31, 181, 199, 106, 157, 184, 84, 204, 176, 115, 121, 50, 45, 127, 4, 150, 254,
                                         138, 236, 205, 93, 222, 114, 67, 29, 24, 72, 243, 141, 128, 195, 78, 66, 215, 61, 156, 180};

float PerlinNoise1234::grad1(int hash, float x)
{
  int h = hash & 15;
  float grad = 1.0 + (h & 7); // Gradient value 1.0, 2.0, ..., 8.0
  if (h & 8)
    grad = -grad;    // and a random sign for the gradient
  return (grad * x); // Multiply the gradient with the distance
}

float PerlinNoise1234::grad2(int hash, float x, float y)
{
  int h = hash & 7;        // Convert low 3 bits of hash code
  float u = h < 4 ? x : y; // into 8 simple gradient directions,
  float v = h < 4 ? y : x; // and compute the dot product with (x,y).
  return ((h & 1) ? -u : u) + ((h & 2) ? -2.0 * v : 2.0 * v);
}

float PerlinNoise1234::grad3(int hash, float x, float y, float z)
{
  int h = hash & 15;       // Convert low 4 bits of hash code into 12 simple
  float u = h < 8 ? x : y; // gradient directions, and compute dot product.
  float v = h < 4 ? y : h == 12 || h == 14 ? x
                                           : z; // Fix repeats at h = 12 to 15
  return ((h & 1) ? -u : u) + ((h & 2) ? -v : v);
}

float PerlinNoise1234::grad4(int hash, float x, float y, float z, float t)
{
  int h = hash & 31;        // Convert low 5 bits of hash code into 32 simple
  float u = h < 24 ? x : y; // gradient directions, and compute dot product.
  float v = h < 16 ? y : z;
  float w = h < 8 ? z : t;
  return ((h & 1) ? -u : u) + ((h & 2) ? -v : v) + ((h & 4) ? -w : w);
}

//---------------------------------------------------------------------
/** 1D float Perlin noise, SL "noise()"
 */
float PerlinNoise1234::noise1(float x)
{
  int ix0, ix1;
  float fx0, fx1;
  float s, n0, n1;

  ix0 = FASTFLOOR(x); // Integer part of x
  fx0 = x - ix0;      // Fractional part of x
  fx1 = fx0 - 1.0f;
  ix1 = (ix0 + 1) & 0xff;
  ix0 = ix0 & 0xff; // Wrap to 0..255

  s = FADE(fx0);

  n0 = grad1(perm[ix0], fx0);
  n1 = grad1(perm[ix1], fx1);
  return 0.188f * (LERP(s, n0, n1));
}

//---------------------------------------------------------------------
/** 1D float Perlin periodic noise, SL "pnoise()"
 */
float PerlinNoise1234::pnoise1(float x, int px)
{
  int ix0, ix1;
  float fx0, fx1;
  float s, n0, n1;

  ix0 = FASTFLOOR(x); // Integer part of x
  fx0 = x - ix0;      // Fractional part of x
  fx1 = fx0 - 1.0f;
  ix1 = ((ix0 + 1) % px) & 0xff; // Wrap to 0..px-1 *and* wrap to 0..255
  ix0 = (ix0 % px) & 0xff;       // (because px might be greater than 256)

  s = FADE(fx0);

  n0 = grad1(perm[ix0], fx0);
  n1 = grad1(perm[ix1], fx1);
  return 0.188f * (LERP(s, n0, n1));
}

//---------------------------------------------------------------------
/** 2D float Perlin noise.
 */
float PerlinNoise1234::noise2(float x, float y)
{
  int ix0, iy0, ix1, iy1;
  float fx0, fy0, fx1, fy1;
  float s, t, nx0, nx1, n0, n1;

  ix0 = FASTFLOOR(x); // Integer part of x
  iy0 = FASTFLOOR(y); // Integer part of y
  fx0 = x - ix0;      // Fractional part of x
  fy0 = y - iy0;      // Fractional part of y
  fx1 = fx0 - 1.0f;
  fy1 = fy0 - 1.0f;
  ix1 = (ix0 + 1) & 0xff; // Wrap to 0..255
  iy1 = (iy0 + 1) & 0xff;
  ix0 = ix0 & 0xff;
  iy0 = iy0 & 0xff;

  t = FADE(fy0);
  s = FADE(fx0);

  nx0 = grad2(perm[ix0 + perm[iy0]], fx0, fy0);
  nx1 = grad2(perm[ix0 + perm[iy1]], fx0, fy1);
  n0 = LERP(t, nx0, nx1);

  nx0 = grad2(perm[ix1 + perm[iy0]], fx1, fy0);
  nx1 = grad2(perm[ix1 + perm[iy1]], fx1, fy1);
  n1 = LERP(t, nx0, nx1);

  return 0.507f * (LERP(s, n0, n1));
}

//---------------------------------------------------------------------
/** 2D float Perlin periodic noise.
 */
float PerlinNoise1234::pnoise2(float x, float y, int px, int py)
{
  int ix0, iy0, ix1, iy1;
  float fx0, fy0, fx1, fy1;
  float s, t, nx0, nx1, n0, n1;

  ix0 = FASTFLOOR(x); // Integer part of x
  iy0 = FASTFLOOR(y); // Integer part of y
  fx0 = x - ix0;      // Fractional part of x
  fy0 = y - iy0;      // Fractional part of y
  fx1 = fx0 - 1.0f;
  fy1 = fy0 - 1.0f;
  ix1 = ((ix0 + 1) % px) & 0xff; // Wrap to 0..px-1 and wrap to 0..255
  iy1 = ((iy0 + 1) % py) & 0xff; // Wrap to 0..py-1 and wrap to 0..255
  ix0 = (ix0 % px) & 0xff;
  iy0 = (iy0 % py) & 0xff;

  t = FADE(fy0);
  s = FADE(fx0);

  nx0 = grad2(perm[ix0 + perm[iy0]], fx0, fy0);
  nx1 = grad2(perm[ix0 + perm[iy1]], fx0, fy1);
  n0 = LERP(t, nx0, nx1);

  nx0 = grad2(perm[ix1 + perm[iy0]], fx1, fy0);
  nx1 = grad2(perm[ix1 + perm[iy1]], fx1, fy1);
  n1 = LERP(t, nx0, nx1);

  return 0.507f * (LERP(s, n0, n1));
}

//---------------------------------------------------------------------
/** 3D float Perlin noise.
 */
float PerlinNoise1234::noise3(float x, float y, float z)
{
  int ix0, iy0, ix1, iy1, iz0, iz1;
  float fx0, fy0, fz0, fx1, fy1, fz1;
  float s, t, r;
  float nxy0, nxy1, nx0, nx1, n0, n1;

  ix0 = FASTFLOOR(x); // Integer part of x
  iy0 = FASTFLOOR(y); // Integer part of y
  iz0 = FASTFLOOR(z); // Integer part of z
  fx0 = x - ix0;      // Fractional part of x
  fy0 = y - iy0;      // Fractional part of y
  fz0 = z - iz0;      // Fractional part of z
  fx1 = fx0 - 1.0f;
  fy1 = fy0 - 1.0f;
  fz1 = fz0 - 1.0f;
  ix1 = (ix0 + 1) & 0xff; // Wrap to 0..255
  iy1 = (iy0 + 1) & 0xff;
  iz1 = (iz0 + 1) & 0xff;
  ix0 = ix0 & 0xff;
  iy0 = iy0 & 0xff;
  iz0 = iz0 & 0xff;

  r = FADE(fz0);
  t = FADE(fy0);
  s = FADE(fx0);

  nxy0 = grad3(perm[ix0 + perm[iy0 + perm[iz0]]], fx0, fy0, fz0);
  nxy1 = grad3(perm[ix0 + perm[iy0 + perm[iz1]]], fx0, fy0, fz1);
  nx0 = LERP(r, nxy0, nxy1);

  nxy0 = grad3(perm[ix0 + perm[iy1 + perm[iz0]]], fx0, fy1, fz0);
  nxy1 = grad3(perm[ix0 + perm[iy1 + perm[iz1]]], fx0, fy1, fz1);
  nx1 = LERP(r, nxy0, nxy1);

  n0 = LERP(t, nx0, nx1);

  nxy0 = grad3(perm[ix1 + perm[iy0 + perm[iz0]]], fx1, fy0, fz0);
  nxy1 = grad3(perm[ix1 + perm[iy0 + perm[iz1]]], fx1, fy0, fz1);
  nx0 = LERP(r, nxy0, nxy1);

  nxy0 = grad3(perm[ix1 + perm[iy1 + perm[iz0]]], fx1, fy1, fz0);
  nxy1 = grad3(perm[ix1 + perm[iy1 + perm[iz1]]], fx1, fy1, fz1);
  nx1 = LERP(r, nxy0, nxy1);

  n1 = LERP(t, nx0, nx1);

  return 0.936f * (LERP(s, n0, n1));
}

//---------------------------------------------------------------------
/** 3D float Perlin periodic noise.
 */
float PerlinNoise1234::pnoise3(float x, float y, float z, int px, int py, int pz)
{
  int ix0, iy0, ix1, iy1, iz0, iz1;
  float fx0, fy0, fz0, fx1, fy1, fz1;
  float s, t, r;
  float nxy0, nxy1, nx0, nx1, n0, n1;

  ix0 = FASTFLOOR(x); // Integer part of x
  iy0 = FASTFLOOR(y); // Integer part of y
  iz0 = FASTFLOOR(z); // Integer part of z
  fx0 = x - ix0;      // Fractional part of x
  fy0 = y - iy0;      // Fractional part of y
  fz0 = z - iz0;      // Fractional part of z
  fx1 = fx0 - 1.0f;
  fy1 = fy0 - 1.0f;
  fz1 = fz0 - 1.0f;
  ix1 = ((ix0 + 1) % px) & 0xff; // Wrap to 0..px-1 and wrap to 0..255
  iy1 = ((iy0 + 1) % py) & 0xff; // Wrap to 0..py-1 and wrap to 0..255
  iz1 = ((iz0 + 1) % pz) & 0xff; // Wrap to 0..pz-1 and wrap to 0..255
  ix0 = (ix0 % px) & 0xff;
  iy0 = (iy0 % py) & 0xff;
  iz0 = (iz0 % pz) & 0xff;

  r = FADE(fz0);
  t = FADE(fy0);
  s = FADE(fx0);

  nxy0 = grad3(perm[ix0 + perm[iy0 + perm[iz0]]], fx0, fy0, fz0);
  nxy1 = grad3(perm[ix0 + perm[iy0 + perm[iz1]]], fx0, fy0, fz1);
  nx0 = LERP(r, nxy0, nxy1);

  nxy0 = grad3(perm[ix0 + perm[iy1 + perm[iz0]]], fx0, fy1, fz0);
  nxy1 = grad3(perm[ix0 + perm[iy1 + perm[iz1]]], fx0, fy1, fz1);
  nx1 = LERP(r, nxy0, nxy1);

  n0 = LERP(t, nx0, nx1);

  nxy0 = grad3(perm[ix1 + perm[iy0 + perm[iz0]]], fx1, fy0, fz0);
  nxy1 = grad3(perm[ix1 + perm[iy0 + perm[iz1]]], fx1, fy0, fz1);
  nx0 = LERP(r, nxy0, nxy1);

  nxy0 = grad3(perm[ix1 + perm[iy1 + perm[iz0]]], fx1, fy1, fz0);
  nxy1 = grad3(perm[ix1 + perm[iy1 + perm[iz1]]], fx1, fy1, fz1);
  nx1 = LERP(r, nxy0, nxy1);

  n1 = LERP(t, nx0, nx1);

  return 0.936f * (LERP(s, n0, n1));
}

//---------------------------------------------------------------------
/** 4D float Perlin noise.
 */

float PerlinNoise1234::noise4(float x, float y, float z, float w)
{
  int ix0, iy0, iz0, iw0, ix1, iy1, iz1, iw1;
  float fx0, fy0, fz0, fw0, fx1, fy1, fz1, fw1;
  float s, t, r, q;
  float nxyz0, nxyz1, nxy0, nxy1, nx0, nx1, n0, n1;

  ix0 = FASTFLOOR(x); // Integer part of x
  iy0 = FASTFLOOR(y); // Integer part of y
  iz0 = FASTFLOOR(z); // Integer part of y
  iw0 = FASTFLOOR(w); // Integer part of w
  fx0 = x - ix0;      // Fractional part of x
  fy0 = y - iy0;      // Fractional part of y
  fz0 = z - iz0;      // Fractional part of z
  fw0 = w - iw0;      // Fractional part of w
  fx1 = fx0 - 1.0f;
  fy1 = fy0 - 1.0f;
  fz1 = fz0 - 1.0f;
  fw1 = fw0 - 1.0f;
  ix1 = (ix0 + 1) & 0xff; // Wrap to 0..255
  iy1 = (iy0 + 1) & 0xff;
  iz1 = (iz0 + 1) & 0xff;
  iw1 = (iw0 + 1) & 0xff;
  ix0 = ix0 & 0xff;
  iy0 = iy0 & 0xff;
  iz0 = iz0 & 0xff;
  iw0 = iw0 & 0xff;

  q = FADE(fw0);
  r = FADE(fz0);
  t = FADE(fy0);
  s = FADE(fx0);

  nxyz0 = grad4(perm[ix0 + perm[iy0 + perm[iz0 + perm[iw0]]]], fx0, fy0, fz0, fw0);
  nxyz1 = grad4(perm[ix0 + perm[iy0 + perm[iz0 + perm[iw1]]]], fx0, fy0, fz0, fw1);
  nxy0 = LERP(q, nxyz0, nxyz1);

  nxyz0 = grad4(perm[ix0 + perm[iy0 + perm[iz1 + perm[iw0]]]], fx0, fy0, fz1, fw0);
  nxyz1 = grad4(perm[ix0 + perm[iy0 + perm[iz1 + perm[iw1]]]], fx0, fy0, fz1, fw1);
  nxy1 = LERP(q, nxyz0, nxyz1);

  nx0 = LERP(r, nxy0, nxy1);

  nxyz0 = grad4(perm[ix0 + perm[iy1 + perm[iz0 + perm[iw0]]]], fx0, fy1, fz0, fw0);
  nxyz1 = grad4(perm[ix0 + perm[iy1 + perm[iz0 + perm[iw1]]]], fx0, fy1, fz0, fw1);
  nxy0 = LERP(q, nxyz0, nxyz1);

  nxyz0 = grad4(perm[ix0 + perm[iy1 + perm[iz1 + perm[iw0]]]], fx0, fy1, fz1, fw0);
  nxyz1 = grad4(perm[ix0 + perm[iy1 + perm[iz1 + perm[iw1]]]], fx0, fy1, fz1, fw1);
  nxy1 = LERP(q, nxyz0, nxyz1);

  nx1 = LERP(r, nxy0, nxy1);

  n0 = LERP(t, nx0, nx1);

  nxyz0 = grad4(perm[ix1 + perm[iy0 + perm[iz0 + perm[iw0]]]], fx1, fy0, fz0, fw0);
  nxyz1 = grad4(perm[ix1 + perm[iy0 + perm[iz0 + perm[iw1]]]], fx1, fy0, fz0, fw1);
  nxy0 = LERP(q, nxyz0, nxyz1);

  nxyz0 = grad4(perm[ix1 + perm[iy0 + perm[iz1 + perm[iw0]]]], fx1, fy0, fz1, fw0);
  nxyz1 = grad4(perm[ix1 + perm[iy0 + perm[iz1 + perm[iw1]]]], fx1, fy0, fz1, fw1);
  nxy1 = LERP(q, nxyz0, nxyz1);

  nx0 = LERP(r, nxy0, nxy1);

  nxyz0 = grad4(perm[ix1 + perm[iy1 + perm[iz0 + perm[iw0]]]], fx1, fy1, fz0, fw0);
  nxyz1 = grad4(perm[ix1 + perm[iy1 + perm[iz0 + perm[iw1]]]], fx1, fy1, fz0, fw1);
  nxy0 = LERP(q, nxyz0, nxyz1);

  nxyz0 = grad4(perm[ix1 + perm[iy1 + perm[iz1 + perm[iw0]]]], fx1, fy1, fz1, fw0);
  nxyz1 = grad4(perm[ix1 + perm[iy1 + perm[iz1 + perm[iw1]]]], fx1, fy1, fz1, fw1);
  nxy1 = LERP(q, nxyz0, nxyz1);

  nx1 = LERP(r, nxy0, nxy1);

  n1 = LERP(t, nx0, nx1);

  return 0.87f * (LERP(s, n0, n1));
}

//---------------------------------------------------------------------
/** 4D float Perlin periodic noise.
 */

float PerlinNoise1234::pnoise4(float x, float y, float z, float w,
                               int px, int py, int pz, int pw)
{
  int ix0, iy0, iz0, iw0, ix1, iy1, iz1, iw1;
  float fx0, fy0, fz0, fw0, fx1, fy1, fz1, fw1;
  float s, t, r, q;
  float nxyz0, nxyz1, nxy0, nxy1, nx0, nx1, n0, n1;

  ix0 = FASTFLOOR(x); // Integer part of x
  iy0 = FASTFLOOR(y); // Integer part of y
  iz0 = FASTFLOOR(z); // Integer part of y
  iw0 = FASTFLOOR(w); // Integer part of w
  fx0 = x - ix0;      // Fractional part of x
  fy0 = y - iy0;      // Fractional part of y
  fz0 = z - iz0;      // Fractional part of z
  fw0 = w - iw0;      // Fractional part of w
  fx1 = fx0 - 1.0f;
  fy1 = fy0 - 1.0f;
  fz1 = fz0 - 1.0f;
  fw1 = fw0 - 1.0f;
  ix1 = ((ix0 + 1) % px) & 0xff; // Wrap to 0..px-1 and wrap to 0..255
  iy1 = ((iy0 + 1) % py) & 0xff; // Wrap to 0..py-1 and wrap to 0..255
  iz1 = ((iz0 + 1) % pz) & 0xff; // Wrap to 0..pz-1 and wrap to 0..255
  iw1 = ((iw0 + 1) % pw) & 0xff; // Wrap to 0..pw-1 and wrap to 0..255
  ix0 = (ix0 % px) & 0xff;
  iy0 = (iy0 % py) & 0xff;
  iz0 = (iz0 % pz) & 0xff;
  iw0 = (iw0 % pw) & 0xff;

  q = FADE(fw0);
  r = FADE(fz0);
  t = FADE(fy0);
  s = FADE(fx0);

  nxyz0 = grad4(perm[ix0 + perm[iy0 + perm[iz0 + perm[iw0]]]], fx0, fy0, fz0, fw0);
  nxyz1 = grad4(perm[ix0 + perm[iy0 + perm[iz0 + perm[iw1]]]], fx0, fy0, fz0, fw1);
  nxy0 = LERP(q, nxyz0, nxyz1);

  nxyz0 = grad4(perm[ix0 + perm[iy0 + perm[iz1 + perm[iw0]]]], fx0, fy0, fz1, fw0);
  nxyz1 = grad4(perm[ix0 + perm[iy0 + perm[iz1 + perm[iw1]]]], fx0, fy0, fz1, fw1);
  nxy1 = LERP(q, nxyz0, nxyz1);

  nx0 = LERP(r, nxy0, nxy1);

  nxyz0 = grad4(perm[ix0 + perm[iy1 + perm[iz0 + perm[iw0]]]], fx0, fy1, fz0, fw0);
  nxyz1 = grad4(perm[ix0 + perm[iy1 + perm[iz0 + perm[iw1]]]], fx0, fy1, fz0, fw1);
  nxy0 = LERP(q, nxyz0, nxyz1);

  nxyz0 = grad4(perm[ix0 + perm[iy1 + perm[iz1 + perm[iw0]]]], fx0, fy1, fz1, fw0);
  nxyz1 = grad4(perm[ix0 + perm[iy1 + perm[iz1 + perm[iw1]]]], fx0, fy1, fz1, fw1);
  nxy1 = LERP(q, nxyz0, nxyz1);

  nx1 = LERP(r, nxy0, nxy1);

  n0 = LERP(t, nx0, nx1);

  nxyz0 = grad4(perm[ix1 + perm[iy0 + perm[iz0 + perm[iw0]]]], fx1, fy0, fz0, fw0);
  nxyz1 = grad4(perm[ix1 + perm[iy0 + perm[iz0 + perm[iw1]]]], fx1, fy0, fz0, fw1);
  nxy0 = LERP(q, nxyz0, nxyz1);

  nxyz0 = grad4(perm[ix1 + perm[iy0 + perm[iz1 + perm[iw0]]]], fx1, fy0, fz1, fw0);
  nxyz1 = grad4(perm[ix1 + perm[iy0 + perm[iz1 + perm[iw1]]]], fx1, fy0, fz1, fw1);
  nxy1 = LERP(q, nxyz0, nxyz1);

  nx0 = LERP(r, nxy0, nxy1);

  nxyz0 = grad4(perm[ix1 + perm[iy1 + perm[iz0 + perm[iw0]]]], fx1, fy1, fz0, fw0);
  nxyz1 = grad4(perm[ix1 + perm[iy1 + perm[iz0 + perm[iw1]]]], fx1, fy1, fz0, fw1);
  nxy0 = LERP(q, nxyz0, nxyz1);

  nxyz0 = grad4(perm[ix1 + perm[iy1 + perm[iz1 + perm[iw0]]]], fx1, fy1, fz1, fw0);
  nxyz1 = grad4(perm[ix1 + perm[iy1 + perm[iz1 + perm[iw1]]]], fx1, fy1, fz1, fw1);
  nxy1 = LERP(q, nxyz0, nxyz1);

  nx1 = LERP(r, nxy0, nxy1);

  n1 = LERP(t, nx0, nx1);

  return 0.87f * (LERP(s, n0, n1));
}
