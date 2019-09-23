import smtplib

sender = "Your Email Here"
password = "Your Password Here"
reciever = "Receiver EMAIL"
SMTP_PORT = 587
message = "INTRUSION!"

email = smtplib.SMTP('smtp.gmail.com', SMTP_PORT)


email.starttls()

email.login(sender, password)

email.sendmail(sender, reciever, message)
print " SENT"
