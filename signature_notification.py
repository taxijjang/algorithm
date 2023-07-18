import sys
import os
import hashlib
import hmac
import base64
import requests
import time

def	make_signature():
	timestamp = int(time.time() * 1000)
	timestamp = str(1688430514690)

	access_key = "EqVamnB17qnn5aPERk12"				# access key id (from portal or Sub Account)
	secret_key = "BOWgRtwQcs9iSv04fxBjh1Noz1vMvw8LN7ZSDa4T"				# secret key (from portal or Sub Account)
	secret_key = bytes(secret_key, 'UTF-8')

	method = "POST"
	uri = "/sms/v2/services/ncp:sms:kr:260252380873:qube/messages"

	message = method + " " + uri + "\n" + timestamp + "\n" + access_key
	message = bytes(message, 'UTF-8')
	signingKey = base64.b64encode(hmac.new(secret_key, message, digestmod=hashlib.sha256).digest())
	print(signingKey)
	return signingKey

if __name__ == "__main__":
	make_signature()