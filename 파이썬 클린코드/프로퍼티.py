import re
EMAIL_FORMAT = re.compile(r'[^@]+@[^@]+[^@]+')

def is_valid_email(potentially_valid_email: str):
    return re.match(EMAIL_FORMAT, potentially_valid_email) is not None

class User:
    def __init__(self, username):
        self.username = username
        self._email = None


    @property
    def email(self):
        return self._email

    @email.setter
    def email(self, new_email):
        if not is_valid_email(new_email):
            raise ValueError(f'유효한 이메일이 아니므로 {new_email} 값을 사용할 수 없음')

        self._email = new_email


if __name__=="__main__":
    new_user = User('김택시')

    print(new_user)


    new_user.email = "gw9122@naver.com"
    print(new_user.email)