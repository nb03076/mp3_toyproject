# MP3 토이 프로젝트

## 사용한 장비

---

- STM32F429ZI(디스커버리 보드)
- 디스커버리 보드 전용 확장 보드

[https://www.waveshare.com/product/mcu-tools/development-boards/stm32-open/open429z-d-standard.htm](https://www.waveshare.com/product/mcu-tools/development-boards/stm32-open/open429z-d-standard.htm)

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

## 구현 방식

---

## 사용한 라이브러리 및 오픈소스 펌웨어

---

- vs1053 라이브러리. 해당 라이브러리는 LL라이브러리로 바꾸고, 기능 추가를 몇 가지 하였음

[https://github.com/eziya/STM32_HAL_VS1053](https://github.com/eziya/STM32_HAL_VS1053)

- u8g2(ssd1306)

[https://github.com/eziya/STM32_LL_EXAMPLES](https://github.com/eziya/STM32_LL_EXAMPLES)

- FATFS. stm cube ide 코드 제너레이터를 이용하였음

[http://elm-chan.org/fsw/ff/00index_e.html](http://elm-chan.org/fsw/ff/00index_e.html)

- freertos 및 segger systemview. 포팅 예제를 참고하였음

[https://wiki.segger.com/FreeRTOS_with_SystemView](https://wiki.segger.com/FreeRTOS_with_SystemView)

- LL라이브러리를 이용한 각종 페리퍼럴 초기화 코드는 대부분 cube ide코드 제너레이터를 이용하였음. LL라이브러리를 이용한 HAL 라이브러리는 직접 코드로 구현하였음

- flipper zero 오픈 소스 펌웨어. 폴더 구조나 일부 소스 코드는 참고하거나 비슷하게 작성하였음.

[https://github.com/flipperdevices/flipperzero-firmware](https://github.com/flipperdevices/flipperzero-firmware)

- infinitime 오픈 소스 펌웨어. 폴더 구조와 초기화 구조만 참고하였음.

[https://github.com/InfiniTimeOrg/InfiniTime.git](https://github.com/InfiniTimeOrg/InfiniTime.git)
