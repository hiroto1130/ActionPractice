#ifndef SCENE_H_
#define SCENE_H_

#include"Graphic.h"
#include"DirectX.h"
#include"Engine.h"

// Step 数
enum SceneStep
{
	InitStep,			//!< 初期化
	MainStep,			//!< メイン
	EndStep,			//!< 終了
};

// SceneId の数
enum SceneId
{
	TitleScene,			//!< タイトルシーン
	ResultSceneTwo,		//!< 難易度設定シーン
	HelpScene,          //!< ヘルプ(遊戯説明画面)シーン
	GameScene,			//!< ゲーム本編シーン
	ResultScene,		//!< リザルトシーン
	SceneIdMax,			//!< シーンID最大
};


class Scene
{
private:

	SceneId g_CurrentSceneId = SceneId::TitleScene;		// 動作中シーンID
	SceneStep g_CurrentSceneStep = SceneStep::InitStep;	// 動作中シーンのステップ

public:

	void ChangeSceneStep(SceneStep next_step);

	void UpdateScene(DirectX* directX,Engine engine,Device device);

	void DrawScene(DirectX* directX,Engine engine);

	/**
	* @brief 現在のシーンIDを戻り値で取得する
	* @return 現在のシーンID
	*/
	SceneId GetCurrentSceneId();

	/**
	* @brief 現在のステップを戻り値で取得する
	* @return 現在のステップ
	*/
	SceneStep GetCurrentSceneStep();

};


#endif // !
