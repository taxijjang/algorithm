import json
#</a></strong>\n<small>   *우리 회사만을 위한 별도의 페이지를 제작할 수 있습니다.</u></small></small>\n<strong><small>➃ 국내 최대 규모의 클래스 확보</strong>\n<small>* 커리어부터 취미까지 15만여편의 다양한 강의들을 가지고 있습니다.</small></small>"
marketing_group = '''
[
  {
    "type": "A",
    "title": "커리어",
    "content": {
      "body": [
        {
          "title": "우리 회사를 위한 단체 수강 플랫폼"

        },
        {
          "title": "커리어 강의도, 에어클래스에서!",
          "description": "➁<big><strong>업무능력이 쑥쑥 오르는</strong>\n\'\'\'\'\'\''''''''<strong>맞춤형 커리어 강의</strong>를 에어클래스에서 만나보세요!</big>\n<small>\n• <strong>  수강 확인증</strong> 등 서류 발급이 가능합니다.\n•  \'https://-수강기간 내 <strong> 횟수 제한 없는 무제한 수강</strong>이 가능합니다.\n•   한 강의 당 3회에 걸쳐 <strong> 수강 일시정지</strong>가 가능합니다.\n\n※ 에어클래스 사업추진본부\n- 전화: 070-4633-5788\n - 이메일: biz@airklass.com\n(상담시간: 평일 오전 10시 ~ 오후 6시)\n(점심시간: 오후 12시 30분 ~ 1시 30분) \n (영업일 중 답변/처리)</small>="
        }
      ]
    },
    "klass_group": [
      {
        "title": "마케팅",
        "klasses": [14]
      },
      {
        "title": "PMP/CAPM/PMI-RMP",
        "klasses": [13]
      },
      {
        "title": "소방기술사 / 소방설비기사(기계, 전기) / 소방설비산업기사(기계)",
        "klasses": [12]    
      },
      {
        "title": "건축전기설비기술사",
        "klasses": [11]
      },
      {
        "title": "ICDL / 포토샵",
        "klasses": [43]
      },
      {
        "title": "MOS",
        "klasses": [64]
      }
    ]
  }
]
'''
# import re
marketing_group = marketing_group.replace('\n','')
print(marketing_group)




data = json.loads(marketing_group)
print(data[0])

# marketing_group = re.sub('[\n\"]]','',marketing_group)
# a = '{"description": " <big><strong>국내 최대</strong> 동영상 강의 플랫폼 <strong> 에어클래스</strong>와 함께 <strong>새로운 배움</strong>을 시작해보세요.</big><strong><u>-  에어클래스와 함께해야 하는 이유</u></strong><strong><small>➀ 구축비, 유지비 전액 무료</strong><small>   *서비스를 이용하고 유지하는데에 별도의 비용이 필요하지 않습니다.</small><strong><small>➁ 제휴사 맞춤형 커스터마이징</strong><small>   *기업에 따라 차별화된 상품, 혜택, 서비스를 제공할 수 있습니다.</small><strong><small>➂  페이지 별도 제작 지원  <small><u><a href=	https://test.airklass.com/pay/DYZGNAEtarget=blank>인앱메시징 테스트 고고</a></strong><small>   *우리 회사만을 위한 별도의 페이지를 제작할 수 있습니다.</u></small></small><strong><small>➃ 국내 최대 규모의 클래스 확보</strong><small>* 커리어부터 취미까지 15만여편의 다양한 강의들을 가지고 있습니다.</small></small>"}'
# marketing_group = marketing_group.replace('\n', ' xx ').replace('\'',' zz ')
# data = str(a).strip("'<>() ").replace("\n","").replace("\r","").replace("\'",'')
# print(data)
# json.loads(data)
# json.loads(marketing_group.replace('\n', 'ㅆ').replace("\'", 'ㅇㅇ'))
# json.loads(marketing_group)

# print(json.loads(marketing_group))
# data = json.loads(marketing_group.replace('<','').replace('>','').replace('\\n','').replace('\\','').replace('\"','').replace('\'',''))
