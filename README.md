
운영체제 Multilevel Feedback Queue
----------------------------------

<br>
<br>

### 1. MLFQ 설명

<br>

![10](https://github.com/Yang-Joon-Ho/Multilevel-Feedback-Queue-/blob/master/%EC%9D%B4%EB%AF%B8%EC%A7%80/mlfq%EC%9E%91%EB%8F%99%EB%B0%A9%EC%8B%9D.PNG)

    각각의 Level을 갖는 여러 개의 Queue가 존재하며, 새로운 Job이 도착하면 이 Queue 안에서 특정 규칙에       따라 우선순위가 변하면서 여러 가지 Job들 중에 하나를 선정해 실행하는 Scheduling 방법론이다.

<br>

### 2. 개발 환경 

<br>

![0](https://github.com/Yang-Joon-Ho/Multilevel-Feedback-Queue-/blob/master/%EC%9D%B4%EB%AF%B8%EC%A7%80/1118-1.PNG)


  - Ubuntu 16.04.1 LTS (64bit)

<br>

### 3. 프로그램 개요

<br>

![21](https://github.com/Yang-Joon-Ho/Multilevel-Feedback-Queue-/blob/master/%EC%9D%B4%EB%AF%B8%EC%A7%80/%EA%B7%9C%EC%B9%99.PNG)

  - MLFQ 규칙

<br>

![22](https://github.com/Yang-Joon-Ho/Multilevel-Feedback-Queue-/blob/master/%EC%9D%B4%EB%AF%B8%EC%A7%80/eh.PNG)

  - Process 목록

<br>


### 3. 프로그램 출력 결과

<br>

#### 1) 시간이 5만큼 지날 때 마다 큐를 초기화 하지 않는 경우

<br>

- time slice = 2^n 으로 설정

<br>

![1](https://github.com/Yang-Joon-Ho/Multilevel-Feedback-Queue-/blob/master/%EC%9D%B4%EB%AF%B8%EC%A7%80/4.PNG)

![2](https://github.com/Yang-Joon-Ho/Multilevel-Feedback-Queue-/blob/master/%EC%9D%B4%EB%AF%B8%EC%A7%80/5.PNG)

<br>

- time slice = 1로 설정

<br>

![3](https://github.com/Yang-Joon-Ho/Multilevel-Feedback-Queue-/blob/master/%EC%9D%B4%EB%AF%B8%EC%A7%80/6.PNG)

![4](https://github.com/Yang-Joon-Ho/Multilevel-Feedback-Queue-/blob/master/%EC%9D%B4%EB%AF%B8%EC%A7%80/7.PNG)

<br>

#### 2) 시간이 5만큼 지날 때 마다 큐를 초기화

<br>

- time slice = 1

<br>

![5](https://github.com/Yang-Joon-Ho/Multilevel-Feedback-Queue-/blob/master/%EC%9D%B4%EB%AF%B8%EC%A7%80/8.PNG)

  
![6](https://github.com/Yang-Joon-Ho/Multilevel-Feedback-Queue-/blob/master/%EC%9D%B4%EB%AF%B8%EC%A7%80/9.PNG)

<br>

- time slice = 2^n

<br>

![7](https://github.com/Yang-Joon-Ho/Multilevel-Feedback-Queue-/blob/master/%EC%9D%B4%EB%AF%B8%EC%A7%80/10.PNG)

![8](https://github.com/Yang-Joon-Ho/Multilevel-Feedback-Queue-/blob/master/%EC%9D%B4%EB%AF%B8%EC%A7%80/11.PNG)
