#include "MyMath.h"
#include <Novice.h>

const char kWindowTitle[] = "LC1A_16_タナハラ_コア_タイトル";

//==============================
// 関数定義
//==============================

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{

    // ライブラリの初期化
    Novice::Initialize(kWindowTitle, 1280, 720);

    // キー入力結果を受け取る箱
    char keys[256] = { 0 };
    char preKeys[256] = { 0 };

    //==============================
    // 変数初期化
    //==============================

    Vector3 rotate = { 0.4f, 1.43f, -0.8f };
    Matrix4x4 rotateXMatrix = MakeRotationXMatrix(rotate.x);
    Matrix4x4 rotateYMatrix = MakeRotationYMatrix(rotate.y);
    Matrix4x4 rotateZMatrix = MakeRotationZMatrix(rotate.z);

    Matrix4x4 rotateXYZMatrix = Multiply(rotateXMatrix, Multiply(rotateYMatrix, rotateZMatrix));

    // ウィンドウの×ボタンが押されるまでループ
    while (Novice::ProcessMessage() == 0) {
        // フレームの開始
        Novice::BeginFrame();

        // キー入力を受け取る
        memcpy(preKeys, keys, 256);
        Novice::GetHitKeyStateAll(keys);

        ///
        /// ↓更新処理ここから
        ///

        ///
        /// ↑更新処理ここまで
        ///

        ///
        /// ↓描画処理ここから
        ///

        Novice::ScreenPrintf(0, 0, "rotateXmatrix");
        MatrixScreenPrintf(0, 16, rotateXMatrix);

        Novice::ScreenPrintf(0, kRowHeight * 5, "rotateYmatrix");
        MatrixScreenPrintf(0, kRowHeight * 6, rotateYMatrix);

        Novice::ScreenPrintf(0, kRowHeight * 11, "rotateZmatrix");
        MatrixScreenPrintf(0, kRowHeight * 12, rotateZMatrix);
        
        Novice::ScreenPrintf(0, kRowHeight * 17, "rotateXYZmatrix");
        MatrixScreenPrintf(0, kRowHeight * 18, rotateXYZMatrix);

        ///
        /// ↑描画処理ここまで
        ///

        // フレームの終了
        Novice::EndFrame();

        // ESCキーが押されたらループを抜ける
        if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
            break;
        }
    }

    // ライブラリの終了
    Novice::Finalize();
    return 0;
}
