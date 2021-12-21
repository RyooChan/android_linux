# Achro-imx6q보드를 이용한 기억력 게임기

## 설계 배경
* 리눅스와 java언어를 활용한 기억력 게임 제작.
* 안드로이드 스튜디오를 통해 기존에 [존재하는 기억력 게임](https://github.com/RyooChan/linux_c_practice)을 다른 언어로 Converting해보기 위함.

## 사용 모듈 및 용도
* FND_DEVICE
    * 화살표 생성
        * header을 수정하였다.
* LED_DEVICE
    * 남은 목숨 표시
* PUSH_SWITCH_DEVICE
    * 정답 입력
* DOT_DEVICE
    * 문제 출력

## 개발 내용
![](https://i.imgur.com/vLEmakZ.png)
---
![](https://i.imgur.com/VmzFsyx.png)
* 8가지 방향에 따라 문제가 출력된다.
* 모든 문제를 맞추면 다음 스테이지로 넘어간다. 틀리는 경우 기회가 차감되고 모든 기회가 차감되면 게임 오버된다.
    * 다음 스테이지는 1개 많은 화살표를 가진 문제가 출력된다.
* 시간 안에 문제를 풀지 못하는 경우도 기회가 차감된다.

## 성취 내용
* 기존에 존재하는 기능을 원하는 언어로 컨버팅 할 수 있는 방안 연구.
* 안드로이드 스튜디오를 통한 리눅스 보드 제어 방법 고찰.
* 기존 C언어를 통해 만든 내용에서 몇 가지 기능들이 제외됨.

## 시연 영상
* Youtube
    * 간단한 기능 및 작동 시연 영상
        * https://youtu.be/h5Swzc4CeJE
