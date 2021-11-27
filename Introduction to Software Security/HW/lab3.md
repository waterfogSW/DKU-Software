# 공격관련 테크닉을 반영한 안드로이드 앱 작성
<div style="text-align: right"> 보안개론 2분반, 32170578, 김산 </div>

## [T1433] Access Call Log

Access Call Log는 안드로이드 스마트폰의 [CallLog](!https://developer.android.com/reference/android/provider/CallLog) API를 활용하여 통화목록을 수집하는 공격기법입니다. Call log를 수집하는 멀웨어에는 Adups, AndroTat, Exodus, Corona Updates등이 있는데 그중 Corona Updates는 코로나 바이러스 관련 정보를 제공하는 애플리케이션을 가장하여 


## [T1414] Capture Clipboard Data

Clipboard Manager API를 통해 global clipboard의 민감한 정보를 얻는 테크닉입니다. 안드로이드에서는 `ClipboardManager.OnprimaryClipChangedListener`를 통해 클립보드의 데이터를 수집할 수 있습니다.

2015년에 발견된 XcodeGhost는 중국 ios개발자들에게 의해 발견되었습니다. 안드로이드 스마트폰의 클립보드는 유저의 패스워드를 패스워드 관리 도구에서 복사할때 사용될 수 있는데 XcodeGhost는 이러한 점을 악용하여 유저 클립보드의 데이터를 읽거나 씁니다.

유저가 ios의 1Password와 같은 패스워드 관리앱을 사용할때,  1Password앱을 열어 저장된 패스워드를 시스템의 클립보드에 복사하여 저장하고, 패스워드를 입력할 로그인 창에 클립보드의 패스워드를 복사하게 됩니다. 이때 악성앱은 시스템의 클립보드로 부터 패스워드를 직접 읽어들일 수 있게 됩니다. 1Password의 보안 모델은 매우 짧은시간동안 클립보드에 패스워드를 저장하는것이지만 언제 앱이 실행될지 악성 프로그램이 읽을 수 있기 때문에 이러한 공격이 성공할 수 있습니다.

```java
    private void checkForPasswordManager() {
        final PackageManager pm = getPackageManager();
        List<ApplicationInfo> packages = pm.getInstalledApplications(PackageManager.GET_META_DATA);
        for (ApplicationInfo packageInfo : packages) {
            if (packageInfo.packageName.equals("com.agilebits.onepassword") ||
                        packageInfo.packageName.equals("com.lastpass.lpandroid")) {
                log.append(packageInfo.packageName);
                log.append(" is installed.\n\n");
            }
        }
    }
```
위 코드의 `checkForPasswordManager()`함수에서 `PacakgeManager.GET_META_DATA`를 통해 패스워드 관리 프로그램이 있는지 확인을 하고, 다음의 `perform clipboardCheck()`함수를 통해 클립보드를 확인하여 민감한 정보에 접근합니다.

```java
private void performClipboardCheck() {
        ClipboardManager cb = (ClipboardManager) getSystemService(CLIPBOARD_SERVICE);
        if (cb.hasPrimaryClip()) {
            ClipData cd = cb.getPrimaryClip();
            if (cd.getDescription().hasMimeType(ClipDescription.MIMETYPE_TEXT_PLAIN)) {
                String clipboard = cd.getItemAt(0).getText().toString();
                log.append(clipboard);
                log.append("\n\n");
            }
        }
    }
```

## [T1409] Access Stored Application Data
디바이스 내의 애플리케이션 데이터에 접근하고 수집하는 공격테크닉입니다.

이탈리아의 eSurv라는 회사에서 만들어진것으로 추정되는 안드로이드 스파이웨어 플렛폼 Exodus는 Exodus one과 Exodus two라는 두단계로 구성되어있습니다. 

첫번째 단계 Exodus one은 IMEI와같은 디바이스에 대한 기본적인 정보만 수집하고, Command & Control서버로 전송하는것처럼 행동합니다. 하지만 정보수집과 전송단계를 거치고나면 추가적인 요청을 하여 두번째 단계의 바이너리 zip파일을 다운로드 합니다.

두번째 단계에서는 Exodus one이 두번째 단계의 payload `mike.jar`을 Android API인 `DexClassLoader()`를 통해 동적으로 로드하고 실행합니다. `mike.jar`파일은 데이터 수집과 분류작업을 하는 기능을 수행합니다.

본 테크닉에서 사용된 `DexClassLoader` API는 `classes.dex`엔트리를 포함하는 `.jar`또는 `.apk`파일로 부터 클래스를 로드합니다. 이는 애플리케이션에 설치되어있지 않은 코드를 수행하는데 사용됩니다. 

```java
public void onClick(View v) {
                final DexClassLoader dexClassLoader = new DexClassLoader("/SDCARD/facebook.apk",
                        getCodeCacheDir().getAbsolutePath(), null, classLoader);
                Log.d(TAG,dexClassLoader.toString());
                Log.d(TAG,"hi");
            }
```
위의 코드는 dexClassLoader를 통해 facbook.apk파일의 클래스를 호출하는 소스코드입니다.  `/SDCARD/facebook.apk`경로에 `facebook.apk`파일이 있음에도 불구하고 ClassLoader referenced unknown path라는 에러가 계속 발생해서 계속 구글링을 해봐도 해결방안을 찾지 못했습니다. 
![image](https://user-images.githubusercontent.com/28651727/121983937-15a42200-cdcd-11eb-992b-a97d5278c0db.png)
