"""
동시성 문제가 발생한것 같습니다.
저라면 이때 kafka 또는 rabbitmq와 같은 message queue를 이용하여 해당 문제를 해결 할것 같습니다.

사용자가 예약을 하는 API를 호출 했을때 서버에서 예약하는 로직을 바로 실행 하지 않고
특정 사용자가 발생시킨 예약 task를 queue로 전송하여 예약 처리를 하는 로직에서
queue에 들어 있는 task를 하나하나 꺼내면서 예약 프로세스를 진행하여 문제를 해결할 것 같습니다.

"""