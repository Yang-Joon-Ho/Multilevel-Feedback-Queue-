
운영체제 Multilevel Feedback Queue
----------------------------------

<br>
<br>

### 1. 개발 환경 

<br>

![0](https://github.com/Yang-Joon-Ho/Multilevel-Feedback-Queue-/blob/master/%EC%9D%B4%EB%AF%B8%EC%A7%80/1118-1.PNG)


  - Ubuntu 16.04.1 LTS (64bit)

<br>

### 2. 프로그램 개요

![21](https://github.com/Yang-Joon-Ho/Multilevel-Feedback-Queue-/blob/master/%EC%9D%B4%EB%AF%B8%EC%A7%80/%EA%B7%9C%EC%B9%99.PNG)

  - MLFQ 규칙

<br>

![22](https://github.com/Yang-Joon-Ho/Multilevel-Feedback-Queue-/blob/master/%EC%9D%B4%EB%AF%B8%EC%A7%80/eh.PNG)

  - Process 목록

<br>


### 3. 프로그램 출력 결과

#### 1) 시간이 5만큼 지날 떄 마다 큐를 초기화 하지 않는 경우

<br>

![1](https://github.com/Yang-Joon-Ho/Multilevel-Feedback-Queue-/blob/master/%EC%9D%B4%EB%AF%B8%EC%A7%80/4.PNG)

  - mode에 따라 time slice가 1혹은 2로 설정됨.
  time slice = 2^n 으로 설정

![2](https://github.com/Yang-Joon-Ho/Multilevel-Feedback-Queue-/blob/master/%EC%9D%B4%EB%AF%B8%EC%A7%80/5.PNG)

![3](https://github.com/Yang-Joon-Ho/Multilevel-Feedback-Queue-/blob/master/%EC%9D%B4%EB%AF%B8%EC%A7%80/6.PNG)

  - time slice = 1로 설정

![4](https://github.com/Yang-Joon-Ho/Multilevel-Feedback-Queue-/blob/master/%EC%9D%B4%EB%AF%B8%EC%A7%80/7.PNG)

<br>

#### 2) 시간이 5만큼 지날 때 마다 큐를 초기화

![5](https://github.com/Yang-Joon-Ho/Multilevel-Feedback-Queue-/blob/master/%EC%9D%B4%EB%AF%B8%EC%A7%80/8.PNG)

  - time slice = 1
  
![6](https://github.com/Yang-Joon-Ho/Multilevel-Feedback-Queue-/blob/master/%EC%9D%B4%EB%AF%B8%EC%A7%80/9.PNG)

![7](https://github.com/Yang-Joon-Ho/Multilevel-Feedback-Queue-/blob/master/%EC%9D%B4%EB%AF%B8%EC%A7%80/10.PNG)

  - time slice = 2^n

![8](https://github.com/Yang-Joon-Ho/Multilevel-Feedback-Queue-/blob/master/%EC%9D%B4%EB%AF%B8%EC%A7%80/11.PNG)
