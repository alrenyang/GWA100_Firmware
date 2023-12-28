/*
 * sonic.c
 *
 *  Created on: Nov 3, 2023
 *      Author: alren
 */

#include "sonic.h"
#include "adc_Dma.h"
#include "wdg.h"

/*
// 칼만 필터 구조체
typedef struct {
    float x_hat;  // 상태 추정값
    float P;      // 오차 공분산 행렬
    float Q;      // 프로세스 노이즈 공분산 행렬
    float R;      // 측정 노이즈 공분산 행렬
} KalmanFilter;

// 칼만 필터 초기화 함수
void KalmanFilter_Init(KalmanFilter* kf, float initial_estimate, float process_noise, float measurement_noise) {
    kf->x_hat = initial_estimate;
    kf->P = 1.0f;  // 초기 오차 공분산 행렬 값
    kf->Q = process_noise;
    kf->R = measurement_noise;
}

// 칼만 필터 업데이트 함수
void KalmanFilter_Update(KalmanFilter* kf, float measurement) {
    // 예측 단계
    float x_hat_minus = kf->x_hat;
    float P_minus = kf->P + kf->Q;

    // 업데이트 단계
    float K = P_minus / (P_minus + kf->R);
    kf->x_hat = x_hat_minus + K * (measurement - x_hat_minus);
    kf->P = (1 - K) * P_minus;
}

int main(void) {
    // STM32 초기화 코드는 여기에 추가

    // 칼만 필터 초기화
    KalmanFilter kf;
    KalmanFilter_Init(&kf, 0.0f, 0.01f, 0.1f);  // 예제 값, 실제 시스템에 맞게 조절

    while (1) {
        // 센서에서 측정한 값
        float measurement = ReadSensor();  // 센서 값을 읽어오는 함수, 실제 시스템에 맞게 수정

        // 칼만 필터 업데이트
        KalmanFilter_Update(&kf, measurement);

        // 추정된 값 사용
        float estimated_value = kf.x_hat;

        // 추정된 값 사용해서 다른 작업 수행

        // 딜레이 루프 또는 인터럽트 핸들링 등 추가
    }
}

 */


typedef struct
{
	float x_hat;	//상태 추정값
	float P;		//오차 공분산 행렬
	float Q;		//노이즈 공분산 행렬
	float R;
}KalmanFilter;


static KalmanFilter kf;

// 칼만 필터 초기화 함수
void KalmanFilter_Init(KalmanFilter* kf, float initial_estimate, float process_noise, float measurement_noise) {
    kf->x_hat = initial_estimate;
    kf->P = 1.0f;  // 초기 오차 공분산 행렬 값
    kf->Q = process_noise;
    kf->R = measurement_noise;
}

// 칼만 필터 업데이트 함수
void KalmanFilter_Update(KalmanFilter* kf, float measurement) {
    // 예측 단계
    float x_hat_minus = kf->x_hat;
    float P_minus = kf->P + kf->Q;

    // 업데이트 단계
    float K = P_minus / (P_minus + kf->R);
    kf->x_hat = x_hat_minus + K * (measurement - x_hat_minus);
    kf->P = (1 - K) * P_minus;
}

float KalmanFiltercal(void)
{
	// 칼만 필터 초기화
	KalmanFilter_Init(&kf, 0.0f, 0.01f, 0.0f);  // 예제 값, 실제 시스템에 맞게 조절

	float measurement = (float)ReadDst();
	KalmanFilter_Update(&kf, measurement);

	        // 추정된 값 사용
	float estimated_value = kf.x_hat;

	return estimated_value;
}

uint32_t ReadDst(void)
{
	uint32_t adc_vaule = 0;
	//float ret = 0.0f;
	uint32_t dist = 0;
	uint32_t dis_ref = 805;

	adc_vaule      = adcReadVoltage(_DEF_CH1);
	dist = (adc_vaule *dis_ref)/254;
	//dist = (float)((adc_vaule * dis_ref) /254);	//to cm

	return dist;
}

uint8_t calData(uint32_t* avg,uint8_t cnt)
{
	uint8_t ret = 0;
	//uint8_t cnt = sizeof(avg) / sizeof(avg[cnt]);

	for (int i = 0; i < cnt; i++) {
		for (int j = i + 1; j < cnt; j++) {
			if (avg[i] == avg[j]) {
				ret = avg[i];
				break; // 중복된 값은 한 번만 보고
			}
		}
	}


	return ret;
}

uint32_t ReadAvgDst(void)
{
	uint32_t avg[10] = {};
	uint32_t ret = 0;
	uint32_t pre_time;
	uint8_t  cnt = 0;
	uint8_t  nWhile = 1;

	for(uint8_t i=0; i<10; i++)
	{
//		avg[cnt] = ReadDst();
		avg[cnt] = (uint32_t)KalmanFiltercal();
		cnt++;
		if(cnt == 10)
		{
			nWhile = 0;
		}

#ifdef _USE_WDG_
		wdgRefresh();
#endif

	}



	ret = calData(avg, cnt);


	return ret;
}



