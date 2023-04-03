import smtplib
import os.path
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart
from email.mime.base import MIMEBase
from email import encoders

# Sender and recipient email addresses
sender_email = raw_input("Sender email: ")
recipient_email = raw_input("Recipient email: ")

# Email content
message = raw_input("Message: ")

# Create a multipart message object
msg = MIMEMultipart()

# Set the sender, recipient, and subject headers
msg['From'] = sender_email
msg['To'] = recipient_email
msg['Subject'] = raw_input("Email Subject: ")

# Add the message to the email
msg.attach(MIMEText(message))

# Attach a file to the email
filename = raw_input("Filename in the directory: ")
if os.path.exists(filename):
    with open(filename, 'rb') as f:
        attachment = MIMEBase('application', 'octet-stream')
        attachment.set_payload(f.read())
        encoders.encode_base64(attachment)
        attachment.add_header('Content-Disposition', 'attachment; filename=' + filename)
        msg.attach(attachment)

# Create a SMTP object
smtp_obj = smtplib.SMTP('smtp.office365.com', 587)

# Start TLS encryption
smtp_obj.starttls()

# Login to the email server
pw = raw_input("Password: ")
smtp_obj.login(sender_email, pw)

# Send the email
smtp_obj.sendmail(sender_email, recipient_email, msg.as_string())

# Close the SMTP connection
smtp_obj.quit()

print("Email sent successfully.")





# import smtplib
# from email.mime.text import MIMEText

# # Sender and recipient email addresses
# sender_email = raw_input("Sender email: ")
# recipient_email = raw_input("Recipient email: ")

# # Email content
# message = raw_input("Message : ")

# # Create a MIME text object
# msg = MIMEText(message)

# # Set the sender, recipient, and subject headers
# msg['From'] = sender_email
# msg['To'] = recipient_email
# msg['Subject'] = "Test email from Python"

# # Create a SMTP object
# smtp_obj = smtplib.SMTP('smtp.office365.com', 587)

# # Start TLS encryption
# smtp_obj.starttls()

# # Login to the email server
# pw = raw_input("Password : ")
# smtp_obj.login(sender_email, pw)

# # Send the email
# smtp_obj.sendmail(sender_email, recipient_email, msg.as_string())

# # Close the SMTP connection
# smtp_obj.quit()

# print("Email sent successfully.")
