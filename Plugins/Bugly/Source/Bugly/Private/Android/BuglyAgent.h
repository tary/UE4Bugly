// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "BuglyAgentInterface.h"

#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"

class FBuglyAgent : public IBuglyAgentInterface
{
public:
	FBuglyAgent();
	virtual ~FBuglyAgent();

	virtual void OnStartup() override;
	virtual void OnShutdown() override;

	virtual void TestJavaCrash() override;
	virtual void TestANRCrash() override;
	virtual void TestNativeCrash() override;

	virtual void SetUserId(const FString& InUserId) override;
	virtual void SetUserSceneTag(int32 InSceneTag) override;
	virtual void PutUserData(const FString& InKey, const FString& InValue) override;
	virtual void LogVerbose(const FString& InTag, const FString& InLog) override;
	virtual void LogDebug(const FString& InTag, const FString& InLog) override;
	virtual void LogInfo(const FString& InTag, const FString& InLog) override;
	virtual void LogWarning(const FString& InTag, const FString& InLog) override;
	virtual void LogError(const FString& InTag, const FString& InLog) override;
	virtual void SetLogCache(int32 ByteSize) override;

	// JNI Methods
	static jmethodID InitCrashReportMethod;
	static jmethodID TestJavaCrashMethod;
	static jmethodID TestANRCrashMethod;
	static jmethodID TestNativeCrashMethod;

	static jmethodID SetUserIdMethod;
	static jmethodID SetUserSceneTagMethod;
	static jmethodID PutUserDataMethod;
	static jmethodID LogVerboseMethod;
	static jmethodID LogDebugMethod;
	static jmethodID LogInfoMethod;
	static jmethodID LogWarningMethod;
	static jmethodID LogErrorMethod;
	static jmethodID SetLogCacheMethod;
};