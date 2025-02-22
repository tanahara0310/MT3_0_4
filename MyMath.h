#pragma once

static const int kRowHeight = 20;
static const int kColumnWidth = 60;

struct Vector3 {
    float x, y, z;

    //Vector3 operator+(const Vector3& other) { return { x + other.x, y + other.y , z + other.z}; }
    //Vector3 operator-(const Vector3& other) { return { x - other.x, y - other.y, z - other.z }; }
    //Vector3 operator*(const Vector3& other) { return { x * other.x, y * other.y, z * other.z }; }
    //Vector3 operator/(const Vector3& other) { return { x / other.x, y / other.y , z / other.z}; }
    //Vector3 operator=(const Vector3& other) { return { x = other.x, y = other.y , z = other.z}; }
    //Vector3 operator+=(const Vector3& other) { return { x += other.x, y += other.y, z += other.z }; }
    //Vector3 operator-=(const Vector3& other) { return { x -= other.x, y -= other.y, z -= other.z }; }
    //Vector3 operator*=(const Vector3& other) { return { x *= other.x, y *= other.y, z *= other.z}; }
    //Vector3 operator/=(const Vector3& other) { return { x /= other.x, y /= other.y, z /= other.z }; }
};

struct Matrix4x4 {

    float m[4][4];
};

//加算
Vector3 Add(const Vector3& v1, const Vector3& v2);

// 減算
Vector3 Subtract(const Vector3& v1, const Vector3& v2);

//スカラー倍
Vector3 Multiply(float scalar, const Vector3& v);

// 内積
float Dot(const Vector3& v1, const Vector3& v2);

//長さ
float Length(const Vector3& v);

// 正規化
Vector3 Normalize(const Vector3& v);

//================================================
// 4x4行列関数
//================================================

//行列の加法
Matrix4x4 Add(const Matrix4x4& m1, const Matrix4x4& m2);

// 行列の減法
Matrix4x4 Subtract(const Matrix4x4& m1, const Matrix4x4& m2);

// 行列の積
Matrix4x4 Multiply(const Matrix4x4& m1, const Matrix4x4& m2);

//逆行列
Matrix4x4 Inverse(const Matrix4x4& m);

// 転置行列
Matrix4x4 Transpose(const Matrix4x4& m);

// 単位行列
Matrix4x4 MakeIdentity4x4();

// 平行移動行列
Matrix4x4 MakeTranslateMatrix(const Vector3& translate);

// 拡大縮小行列
Matrix4x4 MakeScaleMatrix(const Vector3& scale);

//　座標変換
Vector3 TransformCoord(const Vector3& vector, const Matrix4x4& matrix);

// x軸回転行列
Matrix4x4 MakeRotationXMatrix(float radian);

// y軸回転行列
Matrix4x4 MakeRotationYMatrix(float radian);

// z軸回転行列
Matrix4x4 MakeRotationZMatrix(float radian);

//================================================
//　値確認用
//================================================

void MatrixScreenPrintf(int x, int y, const Matrix4x4& matrix);

void VectorScreenPrintf(int x, int y, const Vector3& vector);
