import sys
import os
import tkinter as tk
from tkinter import filedialog
from tkinter import messagebox
import unicodedata
import json
from requests_oauthlib import OAuth1Session

#メモ帳っぽい何か
base=tk.Tk()
base.geometry('400x300')
base.title("メモ帳")

#ファイル形式
fTyp=[('テキストファイル','*.txt')]

#エディタの作成
edit=tk.Text(base,wrap=tk.NONE)
edit.grid(column=0,row=0,sticky=(tk.N,tk.S,tk.E,tk.W))
base.columnconfigure(0,weight=1)
base.rowconfigure(0,weight=1)

#ファイル入出力
with open("無題.txt",'w+')as file:
    data=file.read()
    print(data)

#新規作成
def NewFile():
    ret=messagebox.askyesno('新規作成する','今のメモの内容を削除していいですか（´･ω･)?')
    if ret == True:
        edit.delete('1.0', tk.END)
    else: file_save()

#開く
def file_open():
    filePath=filedialog.askopenfilename(filetypes=fTyp)

    # filename=file.open(filePath)
    # file.show()

    # ↓追記部分
    if filePath:
        edit.delete('1.0', tk.END) # エディタ上のデータを一旦消す
        with open(filePath) as file: # 16行目~19行目のファイル読み込み版
            data = file.read()
            print(filePath + '\n' + data + '\n' + "を読み込みました") # 何読み込んだか出力
            edit.insert(tk.END, data) # エディタに読み込む
            base.title(filePath) # どうせだからタイトルも変えとく
    # ↑追記終了

#保存
def file_save():
    # savePath=filedialog.asksaveasfilename(filetypes=fTyp)
    # filename.save(savePath+".txt")

    # ↓追記部分
    f = filedialog.asksaveasfile(mode='w', defaultextension=".txt")
    if f is None: # 例外処理 保存のダイアログを閉じるかキャンセルした場合は何もしないで関数から抜ける
        print("save is canceled") # キャンセルされたら出力
        return
    saveText = str(edit.get(1.0, tk.END)) # 保存する文字列をエディタから取得
    f.write(saveText) # テキストファイルに書きこみ
    f.close() # テキストファイルを閉じる / 48~50行目は with ~ でも代用可
    print("OK, save is finished" + '\n' + str(f.name)) # 保存できたら出力
    # ↑追記終了

#ツイート処理
def tweet():
    massage = messagebox.askyesno('ツイートする', 'ツイートしてよろしいですか？(´・ω・｀)')
    if massage == True:
        messagebox.showinfo('ツイートする', 'ツイートに成功しました！( ^ω^ )')
    else:
        messagebox.showinfo('ツイートする', 'ツイートしませんでした')
        return
    CONSUMER_KEY = "bn8sLM6U5PxXihCGcQSD1yh05"
    CONSUMER_SECRET = "CK8ycZt6YruHwp8hzSEyJfO3n2VwqP3Kp3XYKFTEhmmbLoWfSl"
    ACCESS_TOKEN = "864386023781933056-jq1mKGLXmC5NkUnp20fCNNOU4pyk4f6"
    ACCESS_TOKEN_SECRET = "DZNP8hYRYzZKkbndmjOLf95yglwEBm97MWcVDR2MRvAWf"
    twitter = OAuth1Session(CONSUMER_KEY,
                CONSUMER_SECRET,
                ACCESS_TOKEN,
                ACCESS_TOKEN_SECRET)
    params = {"status": edit.get('1.0','end -1c')}
    twitter.post("https://api.twitter.com/1.1/statuses/update.json", params = params)
    #ツイート処理終了

#chromeを開く
def im():
    import time
    from selenium import webdriver
    import chromedriver_binary

    driver=webdriver.Chrome()
    driver.get('https://www.google.com/')
    time.sleep(2)
    # driver.quit()
    #chromeを閉じる

#メニューバー
menuber=tk.Menu()

filemenu=tk.Menu(menuber,tearoff=0)
filemenu.add_command(label="新規作成",command=NewFile)
filemenu.add_command(label="ツイートする",command=tweet)
filemenu.add_command(label="開く", command=file_open)
filemenu.add_command(label="名前を付けて保存",command=file_save)
filemenu.add_separator()
filemenu.add_command(label="メモ帳の終了",command=base.quit)
menuber.add_cascade(label="ファイル",menu=filemenu)

rakumenu=tk.Menu(menuber,tearoff=0)
rakumenu.add_command(label="googleを開く",command=im)
menuber.add_cascade(label="検索する",menu=rakumenu)

base.config(menu=menuber)

#スクロールバー(縦のみ）
yscroll = tk.Scrollbar(edit,command=edit.yview)
yscroll.pack(side=tk.RIGHT, fill = "y")
edit['yscrollcommand'] = yscroll.set

base.mainloop()