## `urllib` 模块

有如下四个模块

- [`urllib.request`](https://docs.python.org/zh-cn/3/library/urllib.request.html#module-urllib.request) 打开和读取 URL

- [`urllib.error`](https://docs.python.org/zh-cn/3/library/urllib.error.html#module-urllib.error) 包含 [`urllib.request`](https://docs.python.org/zh-cn/3/library/urllib.request.html#module-urllib.request) 抛出的异常

- [`urllib.parse`](https://docs.python.org/zh-cn/3/library/urllib.parse.html#module-urllib.parse) 用于解析 URL

- [`urllib.robotparser`](https://docs.python.org/zh-cn/3/library/urllib.robotparser.html#module-urllib.robotparser) 用于解析 `robots.txt` 文件

  

```python
#!/usr/bin/env python
# coding=utf-8
"""urllib的使用"""
import urllib.request

#向制定一个URL发送请求，获取回应
response = urllib.request.urlopen("http://www.fangsong.run")
#获取响应内容
content = response.read().decode('utf-8')
fo = open('./fangsong.html', 'w', encoding = 'utf-8')
print(content, file = fo)
fo.close()


#响应头信息
print(response.headers)
#响应码
print(response.status)
```

```python
Connection: close
Content-Length: 48327
Server: GitHub.com
Content-Type: text/html; charset=utf-8
Strict-Transport-Security: max-age=31556952
Last-Modified: Fri, 10 Jul 2020 01:36:45 GMT
ETag: "5f07c62d-bcc7"
Access-Control-Allow-Origin: *
Expires: Thu, 16 Jul 2020 11:33:23 GMT
Cache-Control: max-age=600
X-Proxy-Cache: MISS
X-GitHub-Request-Id: 4A5E:2A37:12F5B9:1755F1:5F1038AA
Accept-Ranges: bytes
Date: Thu, 16 Jul 2020 11:32:11 GMT
Via: 1.1 varnish
Age: 528
X-Served-By: cache-hkg17935-HKG
X-Cache: HIT
X-Cache-Hits: 1
X-Timer: S1594899132.629190,VS0,VE1
Vary: Accept-Encoding
X-Fastly-Request-ID: ea09594f3e3d38c033755ede864ce735303f9638


200
```

##　安装虚拟环境

https://www.cnblogs.com/chjxbt/p/10517952.html

**一、问题：为什么要搭建虚拟环境**

在开发过程中，当需要使用python的某些工具包/框架时需要联网安装。比如联网安装Flask框架flask-0.10.1版本

```
sudo pip install flask==0.10.1
```

使用如上命令，会将flask-0.10.1安装到/usr/local/lib/python3.5/dist-packages路径下

如果在一台电脑上，想开发多个不同的项目， 需要用到同一个包的不同版本， 如果使用上面的命令， 在同一个目录下安装或者更新， 新版本会覆盖以前的版本， 其它的项目就无法运行了。

**二、解决方案：虚拟环境**

虚拟环境可以搭建独立的Python运行环境，使得单个项目的运行环境与其他项目互不影响。

**三、如何搭建虚拟环境（Linux系统）**

步骤：

1、安装虚拟环境

```
sudo apt-get install virtualenv
sudo apt-get install virtualenvwrapper
```

 安装完虚拟环境后，如果提示找不到`mkvirtualenv`命令，须配置环境变量：

```python
# 1、在~（家目录）下创建目录用来存放虚拟环境
mkdir ~/.virtualenvs

# 2、打开~/.bashrc文件，并添加如下：
export WORKON_HOME=$HOME/.myvirtualenvs
source /usr/share/virtualenvwrapper/virtualenvwrapper.sh

# 3、运行
source ~/.bashrc
```

**四、如何使用虚拟环境**

![undefined](http://ww1.sinaimg.cn/large/006Uqzbtly1ggt3lfllh5j30k00bb3zt.jpg)

*创建环境*

```python
cd ~/.myvirtualenvs
mkvirtualenv -p /usr/bin/python3 Python3
```

上面命令第二个`python3`可以自定义

![image.png](http://ww1.sinaimg.cn/large/006Uqzbtly1ggt39wmrl0j30q90a8wno.jpg)

*进入与退出环境*

```bash
fangsong@fangsong-FX503VD:~/.myvirtualenvs$ workon Python3
(Python3) fangsong@fangsong-FX503VD:~/.myvirtualenvs$ deactivate
```

![image.png](http://ww1.sinaimg.cn/large/006Uqzbtly1ggt3iojlt9j30i501x0tl.jpg)

*安装requests*

![image.png](http://ww1.sinaimg.cn/large/006Uqzbtly1ggt3zxs982j30qf0fads6.jpg)

![image.png](http://ww1.sinaimg.cn/large/006Uqzbtly1ggv3dgrlfrj30q00ek13j.jpg)



### requests模块





```python
#!/usr/bin/env python
# coding=utf-8
"""使用requests发送请求和携带参数"""
#导入模块
import requests

url = "https://www.baidu.com"
#发送get请求
response = requests.get("http://www.baidu.com")
response.encoding = 'utf-8'
print(response.text)

#发送get请求,并携带参数
r = requests.get(url, params = {'key1' : 'value1', 'key2' : 'value2'})
r.encoding = 'utf-8'
print(r.text)

#发送post请求,并传输参数
r = requests.post(url, data = {'key' : 'value'})
r.encoding = 'utf-8'
print(r.text)
```

一个简单的爬虫

```python
#!/usr/bin/env python
# coding=utf-8

import requests
src = "https://imgsa.baidu.com/forum/wh%3D144%2C90/sign=c1e4b2dbe2cd7b89e93932823b106e9e/f66fc65c10385343ee1135309713b07ecb80888e.jpg"
response = requests.get(src)
with open('./data/tieba/images/1.jpg', "wb") as file:
    file.write(response.content)
```

思路

>1. 向起始URL发送请求
>2. 从(1) 的相应中提取每个贴吧标题和对应的URL发送请求，获取响应(正则表达式)
>3. 在(2)的响应中,提取每张图片的URL发送请求
>4. (4)保存图片
>5. 从(1)提取下一页中的URL



## 爬虫

第一版：

```python
#!/usr/bin/env python
# coding=utf-8
import re
import requests

name = input('请输入关键字:')
begin = int(input('开始页数:'))
end =int(input('结束页数:'))

w = 0
for i in range(begin, end + 1):
    url = "https://tieba.baidu.com/f?kw="+name+"&ie=utf-8&pn="+str(i * 50)
    r = requests.get(url)
    r.encoding = 'utf-8'
    p = "http.*?\.jpg"
    pic_urls = re.findall(p, r.text);
    print(pic_urls)
    """下载"""
    for pic_url in pic_urls:
        try:
            pic = requests.get(pic_url)
            string = './data/tieba/images/' + str(w + 1) + '.jpg'
            with open(string, 'wb') as f:
                f.write(pic.content)
                print('成功下载第%s张图片: %s' % (str(w + 1), str(pic_url)))
            w+=1
        except Exception as e:
            print('下载第%s张图片时失败: %s' % (str(w + 1), str(pic_url)))
            print(e)
            continue
```

第二版：

1. 提取一级标题:

`<a rel="noreferrer" href="/p/6793476420" title="像我科一样奋斗，随心记录" target="_blank" class="j_th_tit " clicked="true">像我科一样奋斗，随心记录</a>`

`<a rel="noreferrer" href="/p/6661814756" title="渐渐的你笑了，慢慢的我哭了" target="_blank" class="j_th_tit ">渐渐的你笑了，慢慢的我哭了</a>`

所以可以写出正则表达式为：

```python
pattern = re.compile(r'<a rel="noreferrer" href="(/p/\d+?)" title=".+?" target="_blank" class="j_th_tit .*?">(.+?)</a>')
url_title = pattern.findall(content)
```

2. 提取图片:

``<img class="BDE_Image" src="http://tiebapic.baidu.com/forum/w%3D580/sign=8181ff92e036afc30e0c3f6d8318eb85/685d972bd40735fa6403fceb89510fb30e2408b2.jpg" size="174406" changedsize="true" width="560" height="373" style="cursor: url(&quot;//tb2.bdstatic.com/tb/static-pb/img/cur_zin.cur&quot;), pointer;">``

所以可以写出正则表达式为:

```python
content = self.parse_text(url = url)
urls = re.findall(r'<img class="BDE_Image".*?src="(.*?)".*?', content)
```

3. 下一页

`<a href="//tieba.baidu.com/f?kw=%E7%A7%91%E6%AF%94&amp;ie=utf-8&amp;pn=50" class="next pagination-item ">下一页&gt;</a>`

所以可以写出正则表达式为:

```python
next_url = re.findall(r'<a href="(.*?)".*?>下一页&gt;</a>', content)
```

4. 反爬伪装

`Linux:`

```python
self.header = {"User-Agent":"Mozilla/5.0 (X11;\
                Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/71.0.3578.98 Safari/537.36"}
```

`Mac`

```python
self.header = {"User-Agent" : "Mozilla/5.0 (Macintosh;\
                       Intel Mac OS X 10_9_2) AppleWebKit/537.75.14 (KHTML, like Gecko) Version/7.0.3 Safari/537.75.14"}
```

完整代码:

```python
#!/usr/bin/env python
# coding=utf-8
"""爬百度贴吧"""

import requests
import re

class TiebaSpider:
    """贴吧爬虫"""
    def __init__(self):
        """初始化参数"""
        self.kw = input('关键词：')
        self.base_url = 'https://tieba.baidu.com/f'
        self.page_num = 1
        """
        self.header = {"User-Agent" : "Mozilla/5.0 (Macintosh;\
                       Intel Mac OS X 10_9_2) AppleWebKit/537.75.14 (KHTML, like Gecko) Version/7.0.3 Safari/537.75.14"}
        """
        self.header = {"User-Agent":"Mozilla/5.0 (X11;\
                Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/71.0.3578.98 Safari/537.36"}

        self.title = ''

    def parse_text(self, url, params = None):
        """发送请求，获取响应内容"""
        req = requests.get(url, headers = self.header, params = params)
        return req.text#响应对象的文本信息

    def parse_byte(self, url, params = None):
        req = requests.get(url, headers = self.header, params = params)
        return req.content#响应对象的content

    def page(self, content):
        """解析每一页"""
        print("第{}页爬取中...".format(self.page_num))
        self.page_num += 1
        pattern = re.compile(r'<a rel="noreferrer" href="(/p/\d+?)" title=".+?" target="_blank" class="j_th_tit .*?">(.+?)</a>')
        url_title = pattern.findall(content)
        for url, title in url_title:
            self.title = title
            self.detail('https://tieba.baidu.com' + url)
            #保存标题
            self.save_title()
            #判断下一页
            next_url = re.findall(r'<a href="(.*?)".*?>下一页&gt;</a>', content)
        if next_url:#下一页存在
            next_url = 'https:' + next_url[0]
            content = self.parse_text(url = next_url)
            self.page(content)
        else:
            print('爬虫结束...共爬取{}页！'.format(self.page_num))

    def detail(self, url):
        """每一个帖子的详情"""
        content = self.parse_text(url = url)
        urls = re.findall(r'<img class="BDE_Image".*?src="(.*?)".*?', content)
        for url in urls:
            self.save_img(url = url)

    def save_title(self):
        """保存帖子的标题"""
        with open('./data/tieba/tieba_{}.txt'.format(self.kw), 'a', encoding = 'utf-8') as file:
            file.write(self.title)
            file.write('\n')

    def save_img(self, url):
        """保存图片"""
        content = self.parse_byte(url = url)
        image_path = './data/tieba/images/{}.jpg'.format(self.title)
        try:
            with open(image_path, 'wb') as file:
                file.write(content)
        except:
            pass

    def start(self):
        """开始爬虫"""
        print('爬虫开始...')
        content = self.parse_text(url = self.base_url, params = {'kw' : self.kw, 'ie' : 'utf-8', 'fr' : 'search'})
        self.page(content)

if __name__ == '__main__':
    spider = TiebaSpider()
    spider.start()
```

**框架**

```python
#!/usr/bin/env python
# coding=utf-8
"""
爬百度贴吧
"""

import requests
import re 

class TiebaSpider:
    """贴吧爬虫"""
    def __init__(self):
        """初始化参数"""
        self.kw = imput('请输入关键词:')
        self.base_url = 'https://tieba.baidu.com/f'
        self.page_num = 1
        self.header = {"User-Agent":"Mozilla/5.0 (X11;\
                Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/71.0.3578.98 Safari/537.36"}
        self.title = ''

    def parse_text(self, url, params = None):
        """发送请求，获取相应内容"""

        return #响应对象的文本信息
    
    def parse_byte(self, url, params=None):

        return #响应对象的content

    def page(self, content):
        """解析每一页"""
        print("第()页爬取中...".format(self.page_num))


        #判断下一页
        if #下一页存在:
            self.parse_text()
        else:
            print('爬虫结束...爬取{}页！'.format(self.page_num))

    def save_title(self):
        """保存帖子的标题"""

    def save_img(self, url):
        """保存图片"""


    def start(self):
        """开始爬虫"""
        print('爬虫开始...')
        content = self.parse_text(url = self.base_url, params = {'kw' : self.kw. 'ie' : 'utf-8', 'fr' : 'search'})
        self.page(content)



if __name__=='__main__':
    spider = TiebaSpider()
    spider.start()
```

