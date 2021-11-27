# [LAB 3] 공격 테크닉관련 안드로이드 앱 작성
<div style="text-align: right"> 보안개론 2분반, 32170578, 김산 </div>

## Access Stored Application Data
디바이스 내에 저장되어있는 애플리케이션의 데이터에 접근하여 공격하는 방식입니다. 주로 Facebook, WeChat, Gmail과 같은 유명한 애플리케이션을 타겟으로 합니다.

Access Stored Apllication Data기법을 이용한 대표적인 사례로 Exodus라는 스파이웨어 앱이 있습니다. Exodus는

Adversaries may access and collect application data resident on the device. Adversaries often target popular applications such as Facebook, WeChat, and Gmail.[1]

This technique requires either escalated privileges or for the targeted app to have stored the data in an insecure manner (e.g., with insecure file permissions or in an insecure location such as an external storage directory).