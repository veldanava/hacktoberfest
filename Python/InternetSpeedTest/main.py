import speedtest

def MB(bytes):
    return int(bytes/(1024*1024))
def Speed():
    download = MB(st.download())
    upload = MB(st.upload())
    ping = st.results.ping
    print(f"Download : {download} MB/s\tUpload : {upload} MB/s\tPing : {ping} ms")
    Speed()
if __name__=="__main__":
    st = speedtest.Speedtest()
    print("Internet Speed")
    Speed()

