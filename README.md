# MP3 토이 프로젝트

## 사용한 장비

---

- STM32F429ZI(디스커버리 보드)

## 사용한 페리퍼럴

---

- UART1 : 디버깅 용도
- I2C1 : DS3231
- SPI2 : SSD1306
- SPI4 : VS1053B
- ADC1 : VS1053B 볼륨 조절용 가변저항
- SDIO : SD카드
- TIM4 :  VS1053B는 타이머 인터럽트를 이용하여 음악 재생
- GPIO : 각종 버튼들

## 태스크

---

- 입력

```c
각종 버튼 키 입력을 다른 태스크에 전해줍니다.
EXTI 핸들러에서 큐를 전송합니다.
```

- 디스플레이

```c
버튼 키관련 큐를 받아서 처리합니다.
디스플레이 레이어를 만들어서 해당 레이어에 맞는 버튼 키 이벤트를 적절하게 처리합니다.
주로 MP3 태스크에 큐를 전송하거나 디스플레이 표시하는 용도로 사용합니다.
```

- MP3

```c
디스플레이에서 보낸 큐에 따라서 노래 재생, 정지를 수행합니다.
```

## 동작 사진

---

- 노래 리스트
    
![KakaoTalk_20230209_184129709](https://user-images.githubusercontent.com/88184255/217788264-c2b655b6-67bd-4827-88db-4f90d81a49ac.jpg)
    

```c
위, 아래 버튼을 이용하여 노래 목록을 검색 가능하게끔 구현하였습니다.
매 초마다 RTC 모듈을 이용하여 시간을 갱신하였고, 음악이 재생되고 있는 경우 우측 상단에
곡이 재생되고 있는 경우 P 멈춰있는 경우 S로 표시하였습니다.
OK 버튼을 누르면 해당하는 곡을 재생하게끔 구현하였습니다.
```

- MP3 재생화면
    
    ![KakaoTalk_20230209_184159947.jpg](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/ad3b03de-8b0c-43d5-aea6-2747d8007c21/KakaoTalk_20230209_184159947.jpg)
    

```c
현재 시간과 재생중인 곡을 표시합니다.
```

## 만들 예정인 기능

---

1. 소프트웨어 타이머를 이용한 버튼 채터링 방지용 코드
2. 소프트웨어 타이머를 이용한 곡 재생 시간 및 그래픽 표기
3. USB나 SD카드를 이용한 부트로더

## 사용한 라이브러리 및 오픈소스 펌웨어

---

- vs1053 라이브러리. 해당 라이브러리는 LL라이브러리로 바꾸고, 기능 추가를 몇 가지 하였습니다.

[https://github.com/eziya/STM32_HAL_VS1053](https://github.com/eziya/STM32_HAL_VS1053)

- u8g2(ssd1306)

[https://github.com/eziya/STM32_LL_EXAMPLES](https://github.com/eziya/STM32_LL_EXAMPLES)

- FATFS. stm cube ide 코드 제너레이터를 이용하였습니다.

[http://elm-chan.org/fsw/ff/00index_e.html](http://elm-chan.org/fsw/ff/00index_e.html)

- freertos 및 segger systemview. 포팅 예제를 참고하였습니다.

[https://wiki.segger.com/FreeRTOS_with_SystemView](https://wiki.segger.com/FreeRTOS_with_SystemView)

- LL라이브러리를 이용한 각종 페리퍼럴 초기화 코드는 대부분 cubemx 코드 제너레이터를 이용하였습니다. LL라이브러리를 이용한 HAL 라이브러리는 직접 코드로 구현하였습니다.

- flipper zero 오픈 소스 펌웨어. 폴더 구조나 일부 소스 코드는 참고하거나 비슷하게 작성하였습니다.

[https://github.com/flipperdevices/flipperzero-firmware](https://github.com/flipperdevices/flipperzero-firmware)

- infinitime 오픈 소스 펌웨어. 폴더 구조와 초기화 구조만 참고하였습니다.

[https://github.com/InfiniTimeOrg/InfiniTime.git](https://github.com/InfiniTimeOrg/InfiniTime.git)
