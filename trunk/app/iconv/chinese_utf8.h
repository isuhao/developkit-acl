#include "stdafx.h"
#include "charset.h"

unsigned char chinese_utf8_list[] = "र฿ღ‐—―‖‘’“”†‡•…‰‱′″‹›※‿₠₡₢₣₤₥₦₧₨₩₪₫€₭₮₯₰₱₲₳₴₵₸₹ℂ℃℅℉ℊℋℌℍℎℐℑℒℓℕ№℗℘ℙℚℛℜℝ℠™ℤℨℬℭ℮ℯℰℱℳℴ⅓⅔⅕⅖⅗⅘⅙⅚⅛⅜⅝⅞⅟ⅠⅡⅢⅣⅤⅥⅦⅧⅨⅩⅪⅫⅬⅭⅮⅯⅰⅱⅲⅳⅴⅵⅶⅷⅸⅹⅺⅻⅼⅽⅾⅿ←↑→↓↔↕↖↗↘↙↚↛↜↝↞↟↠↡↢↣↤↥↦↧↨↩↪↫↬↭↮↯↰↱↲↳↴↵↶↷↸↹↺↻↼↽↾↿⇀⇁⇂⇃⇄⇅⇆⇇⇈⇉⇊⇋⇌⇍⇎⇏⇐⇑⇒⇓⇔⇕⇖⇗⇘⇙⇚⇛⇜⇝⇞⇟⇠⇡⇢⇣⇤⇥⇦⇧⇨⇩⇪∈∏∑√∝∞∟∠∥∧∨∩∪∫∬∭∮∯∰∱∲∳∴∵∶∷∽≂≃≄≅≆≇≈≉≊≋≌≍≎≏≐≑≒≓≔≕≖≗≘≙≚≛≜≝≞≟≠≡≢≣≤≥≦≧≨≩≮≯⊕⊗⊙⊥⊰⊱⊿⋆⋚⋛⌒⌘⏎①②③④⑤⑥⑦⑧⑨⑩⑪⑫⑬⑭⑮⑯⑰⑱⑲⑳⑴⑵⑶⑷⑸⑹⑺⑻⑼⑽⑾⑿⒀⒁⒂⒃⒄⒅⒆⒇⒈⒉⒊⒋⒌⒍⒎⒏⒐⒑⒒⒓⒔⒕⒖⒗⒘⒙⒚⒛⒜⒝⒞⒟⒠⒡⒢⒣⒤⒥⒦⒧⒨⒩⒪⒫⒬⒭⒮⒯⒰⒱⒲⒳⒴⒵ⒶⒷⒸⒹⒺⒻⒼⒽⒾⒿⓀⓁⓂⓃⓄⓅⓆⓇⓈⓉⓊⓋⓌⓍⓎⓏⓐⓑⓒⓓⓔⓕⓖⓗⓘⓙⓚⓛⓜⓝⓞⓟⓠⓡⓢⓣⓤⓥⓦⓧⓨⓩ⓪⓫⓬⓭⓮⓯⓰⓱⓲⓳⓴─━│┃┄┅┆┇┈┉┊┋┌┍┎┏┐┑┒┓└┕┖┗┘┙┚┛├┝┞┟┠┡┢┣┤┥┦┧┨┩┪┫┬┭┮┯┰┱┲┳┴┵┶┷┸┹┺┻┼┽┾┿╀╁╂╃╄╅╆╇╈╉╊╋╌╍╎╏═║╒╓╔╕╖╗╘╙╚╛╜╝╞╟╠╡╢╣╤╥╦╧╨╩╪╫╬╭╮╯╰╳▀▁▂▃▄▅▆▇█▉▊▋▌▍▎▏▐░▒▓▔▕■□▢▣▤▥▦▧▨▩▪▫▬▭▮▯▲△▴▵▶▷▸▹►▻▼▽▾▿◀◁◂◃◄◅◆◇◈◉◊○◌◍◎●◐◑◒◓◔◕◖◗◘◙◢◣◤◥◦☀☁☂☃☄★☆☇☈☉☊☋☌☍☎☏☐☑☒☓☚☛☜☝☞☟☠☢☣☤☥☦☧☨☩☪☬☭☮☯☰☱☲☳☴☵☶☷☸☹☺☻☼☽☾☿♀♁♂♆♈♋♐♒♓♔♕♖♗♘♙♚♛♜♝♞♟♠♡♢♣♤♥♦♧♨♩♪♫♬♭♮♯⚘✁✂✃✄✆✈✉✌✍✎✏✐✑✒✓✔✕✖✗✘✙✚✛✜✝✞✠✡✢✣✤✥✦✧✩✪✫✬✭✮✯✰✱✲✳✴✵✶✷✸✹✺✻✼✽✾✿❀❁❂❃❄❅❆❇❈❉❊❋❏❐❑❒❖❝❞❣❤❥❦❧❶❷❸❹❺❻❼❽❾❿➀➁➂➃➄➅➆➇➈➉➊➋➌➍➎➏➐➑➒➓➔➘➙➚➛➜➝➞➟➠➡➢➣➤➥➦➧➨➩➪➫➬➭➮➯➱➲➳➴➵➶➷➸➹➺➻➼➽➾　、。〃々〆〈〉《》「」『』【】〒〓〔〕〖〗〝〞〡〢〣〤〥〦〧〨〩ぁあぃいぅうぇえぉおかがきぎくぐけげこごさざしじすずせぜそぞただちぢっつづてでとどなにぬねのはばぱひびぴふぶぷへべぺほぼぽまみむめもゃやゅゆょよらりるれろゎわゐゑをんゔゕゖ゠ァアィイゥウェエォオカガキギクグケゲコゴサザシジスズセゼソゾタダチヂッツヅテデトドナニヌネノハバパヒビピフブプヘベペホボポマミムメモャヤュユョヨラリルレロヮワヰヱヲンヴヵヶヷヸヹヺ・ーヽヾヿㄅㄆㄇㄈㄉㄊㄋㄌㄍㄎㄏㄐㄑㄒㄓㄔㄕㄖㄗㄘㄙㄚㄛㄜㄝㄞㄟㄠㄡㄢㄣㄤㄥㄦㄧㄨㄩㇰㇱㇲㇳㇴㇵㇶㇷㇸㇹㇺㇻㇼㇽㇾㇿ㈠㈡㈢㈣㈤㈥㈦㈧㈨㈩㉿㊀㊁㊂㊃㊄㊅㊆㊇㊈㊉㊊㊋㊌㊍㊎㊏㊐㊑㊒㊓㊔㊕㊖㊗㊘㊙㊚㊛㊜㊝㊞㊟㊠㊡㊢㊣㊤㊥㊦㊧㊨㊩㊪㊫㊬㊭㊮㊯㊰㋀㋁㋂㋃㋄㋅㋆㋇㋈㋉㋊㋋㍘㍙㍚㍛㍜㍝㍞㍟㍠㍡㍢㍣㍤㍥㍦㍧㍨㍩㍪㍫㍬㍭㍮㍯㍰㍿㎎㎏㎜㎝㎞㎡㏄㏎㏑㏒㏕㏠㏡㏢㏣㏤㏥㏦㏧㏨㏩㏪㏫㏬㏭㏮㏯㏰㏱㏲㏳㏴㏵㏶㏷㏸㏹㏺㏻㏼㏽㏾一丁七万丈三上下不与丑专且世丘丙业丛东丝丟丢两严並丧个丫中丰串临丸丹为主丽举乃久么义之乌乍乎乏乐乒乓乔乖乘乙九乞也习乡书买乱乳乾亂了予争事二于亏云互五井亚些亞亡亢交亥亦产亨亩享京亭亮亲人亿什仁仅仆仇今介仍从仑仓仔仕他仗付仙仟代令以仪们仰仲件价任份仿企伊伍伎伏伐休众优伙会伞伟传伤伦伪伯估伴伶伸伺似佃但位低住佐佑体何余佛作你佣佩佬佯佰佳使侄來侈例侍侖侗供依侠侣侥侦侧侨侩侮侯侵侶便促俄俊俏俐俗俘保俞俠信俩俭修俯俱俺倆倉個倍們倒倔倘候倚借倡倦倪倫债值倾假偉偏做停健側偵偶偷偿傀傅傈傍傑傘備傣储催傭傲傳債傷傻傾僅像僑僚僞僥僧僳僵價僻儀億儈儉儒償儡優儲儿兀允元兄充兆先光克兌免兑兒兔党兜兢入內全兩八公六兰共关兴兵其具典兹养兼兽冀内円冈冉冊册再冒冕冗写军农冠冤冪冬冯冰冲决况冶冷冻净凄准凉凋凌凍减凑凛凜凝几凡凤凭凯凰凱凳凶凸凹出击函凿刀刁刃分切刊刑划列刘则刚创初删判別刨利刪别刮到制刷券刹刺刻刽剁剂剃則削前剐剑剔剖剛剝剥剧剩剪剮副割創剿劃劄劇劈劉劊劍劑力劝办功加务劣动助努劫励劲劳势勁勃勇勉勋勒動勘務勝勞募勢勤勳勵勸勺勻勾勿匀包匆匈化北匙匝匠匡匣匪匯匹区医匿區十千卄升午卉半卍华协卐卑卒卓協单卖南博卜卞占卡卢卤卧卫卯印危即却卵卷卸卻卿厂厄厅历厉压厌厕厘厚原厢厦厨厩厭厲去县叁参參又叉及友双反发叔取受变叙叛叠叢口古句另只叫召叭叮可台史右叶号司叹叼吁吃各合吉吊同名后吏吐向吓吕吗君吝吞吟吠否吧吨吩含听吭吮启吱吳吴吵吸吹吻吼吾呀呂呆呈告呐呕员呛呜呢周味呵呸呻呼命咀咆咋和咎咏咐咒咕咖咙咨咬咯咱咳咸咽哀品哄哆哇哈哉响哎哑哗哟員哥哦哨哩哪哭哮哲哺哼唁唆唇唉唐唤唬售唯唱唾啃啄商啊問啓啞啡啤啥啦啪啮啸啼喀喂善喇喉喊喘喚喜喝喧喪喬單喲喳喷喻嗅嗆嗎嗓嗚嗜嗡嗣嗽嘉嘎嘔嘗嘘嘛嘩嘯嘱嘲嘴嘶嘻嘿噎噓器噪噬噴噶噸嚇嚎嚏嚣嚨嚴嚷嚼囂囊囍囑囚四回因团囤囪园困囱围固国图圃圆圈國圍園圓圖團土圣在圭地场圾址均坊坍坎坏坐坑块坚坛坝坞坟坠坡坤坦坪坯坷垂垃垄型垒垛垢垣垦垫垮埂埃埋城埔域埠執培基堂堅堆堑堕堡堤堪堯堰報場堵堿塊塌塑塔塗塘塞塢填塵塹境墅墊墒墓墙墜增墟墨墩墮墳墾壁壇壓壕壘壞壟壤壩士壬壮壯声壳壶壹壺壽处备复夏夕外多夜够夠夢夥大天太夫央夯失头夷夸夹夺夾奄奇奈奉奋奎奏契奔奖套奠奢奥奧奪奮女奴奶奸她好如妄妆妇妈妊妒妓妖妙妝妥妨妮妹妻姆始姐姑姓委姚姜姥姨姬姻姿威娃娄娇娘娛娜娟娠娥娩娱娶婁婆婉婚婦婪婴婶婿媒媚媳媽嫁嫂嫉嫌嫡嫩嬌嬰嬸子孔孕字存孙孜孝孟季孤学孩孪孫孰孵學孺孽孿宁它宅宇守安宋完宏宗官宙定宛宜宝实宠审客宣室宦宪宫宮宰害宴宵家容宽宾宿寂寄寅密寇富寐寒寓寝寞察寡寢寥實寨審寫寬寵寶寸对寺寻导寿封射将將專尉尊尋對導小少尔尖尘尚尝尤尧就尸尹尺尼尽尾尿局屁层居屆屈屉届屋屍屎屏屑展屜属屠屡屢層履屬屯山屹屿岁岂岔岗岛岡岩岭岳岸岿峙峡峦峨峪峭峰島峻峽崇崎崔崖崗崩崭嵌嶄嶺嶼嶽巋巍巒巜川州巡巢工左巧巨巩巫差己已巳巴巷巾币市布帅帆师希帐帕帖帘帚帛帜帝帥带帧師席帮帳帶常帽幀幂幅幌幕幟幢幣幫干平年并幸幹幻幼幽幾广庄庆庇床序庐库应底店庙庚府庞废度座庫庭庶康庸廁廂廄廈廉廊廓廖廚廟廠廢廣廬廳延廷建开异弃弄弊弍弎式弐弓引弗弘弛弟张弥弦弧弯弱張強弹强彈彌彎归当录彜彝形彤彥彦彩彪彬彭彰影役彻彼往征径待很徊律後徐徑徒得徘從御循微德徹徽心必忆忌忍志忘忙忠忧快忱念忻忽忿怀态怂怎怒怔怕怖怜思怠急性怨怪怯总恃恋恍恐恒恕恢恤恥恨恩恫恬恭息恳恶恼恿悄悅悉悍悔悟悠患悦您悬悯悲悶悸悼情惊惋惑惕惜惟惠惡惦惧惨惩惫惭惮惯惰惱想惶惹惺愁愈愉意愚愛感愤愧愿慈態慌慎慑慕慘慚慢慣慧慨慫慮慰慶慷憂憊憋憎憐憑憚憤憨憫憲憶憾懂懇懈應懊懒懦懲懶懷懸懼懾戀戈戊戌戍戎戏成我戒或战戚截戮戰戲戳戴戶户房所扁扇手才扎扑扒打扔托扛扡扣扦执扩扫扬扭扮扯扰扳扶批扼找承技抄抉把抑抒抓投抖抗折抚抛抠抡抢护报抨披抬抱抵抹押抽抿拂拄担拆拇拈拉拌拍拎拐拒拓拔拖拘拙招拜拟拢拣拥拦拧拨择括拭拯拱拳拴拷拼拽拾拿持挂指按挎挑挖挚挛挝挞挟挠挡挣挤挥挨挪挫振挺挽挾捂捅捆捉捌捍捎捏捐捕捞损捡换捣捧据捶捷捻掀掂掃掄掇授掉掌掏掐排掖掘掙掠探掣接控推掩措掳掷掸掺揀揉揍描提插揖揚換握揣揩揪揭揮援揽搀搁搂搅損搏搐搓搔搖搗搜搞搪搬搭搶携搽摄摆摇摈摊摔摘摟摧摩摯摳摸摹摻撂撅撇撈撐撑撒撓撕撚撞撣撤撥撩撫撬播撮撰撲撵撻撼撾撿擁擂擄擅擇擊擋操擎擒擔據擞擠擡擦擬擯擰擱擲擴擺擻擾攀攆攏攒攔攘攙攜攝攢攣攤攪攫攬支收改攻放政故效敌敏救敖敗敘教敛敝敞敢散敦敬数敲整敵敷數斂斃文斋斌斑斗料斜斟斡斤斥斧斩斬断斯新斷方施旁旅旋族旗无既日旦旧旨早旬旭旱时旷旺昂昆昌明昏易昔星映春昧昨昭是昼显時晃晉晋晌晒晓晕晚晝晤晦晨普景晰晴晶智晾暂暇暈暑暖暗暢暫暮暴曆曉曙曝曠曬曰曱曲曳更書曹曼曾替最會月有朋服朔朗望朝期朤木未末本札术朱朴朵机朽杀杂权杆杉李杏材村杖杜束杠条来杨杭杯杰東松板极构枉析枕林枚果枝枢枣枪枫枯架枷柄柏某柑柒染柔柜柞柠查柬柯柱柳柴柵柿栅标栈栋栏树栓栖栗校株样核根格栽桂桃桅框案桌桐桑桓桔档桥桨桩桶梁梅梆梗條梢梦梧梨梭梯械梳检棄棉棋棍棒棕棗棘棚棟棠棧森棱棲棵棺椅植椎椒椭椰椽椿楊楓楔楚楞業極楷楼概榆榔榜榨榮榴榷構槍槐槛槳槽樁樂樊樓標樞樟模樣横樱樸樹橇橋橙機橡橢橫橱檀檄檔檢檬檸檻櫃櫥櫻欄權欠次欢欣欧欲欺欽款歇歉歌歎歐歡止正此步武歧歪歲歸歹死歼殃殆殉殊残殖殘殲殴段殷殺殼殿毀毁毅毆毋母每毒比毕毖毗毙毛毡毫毯氈氏民氓气氖氛氟氢氣氦氧氨氫氮氯氰水永氺汀汁求汇汉汐汕汗汙汛汝汞江池污汤汪汰汲汹決汽汾沁沂沃沈沉沏沒沖沙沛沟没沤沥沦沧沪沫沮河沸油治沼沽沾沿況泄泅泉泊泌法泛泞泡波泣泥注泪泰泳泵泻泼泽洁洋洒洗洛洞津洪洱洲洶活洼洽派流浅浆浇浊测济浑浓浙浚浦浩浪浮浴海浸涂涅消涉涌涎涕涛涝涟涡涣涤润涧涨涩涪涯液涵涸涼淀淄淆淋淌淑淒淖淘淚淡淤淨淩淪淫淬淮深淳淵混淹淺添清渊渍渐渔渗渙減渝渠渡渣渤渦温測渭港渴游渺渾湃湊湍湖湘湛湧湯湾湿溃溅溉源溜溝溢溪溫溯溶溺滁滄滅滇滋滌滑滓滔滚滞满滤滥滦滨滩滬滯滲滴滾滿漁漂漆漏漓演漚漠漢漣漫漬漱漲漳漸漾漿潍潑潔潘潛潜潞潤潦潭潮潰澀澄澆澇澈澎澗澜澡澤澱澳激濁濃濒濕濘濟濤濫濰濱濺濾瀉瀑瀕瀝瀾灌灑灘灣灤火灭灯灰灵灶灸灼災灾灿炉炊炎炒炔炕炙炬炭炮炯炳炸点炼炽烁烂烃烈烏烘烙烛烟烤烦烧烩烫烬热烯烴烷烹烽焉焊焕焙焚無焦焰然煉煌煎煙煞煤煥照煩煮煽熄熊熏熒熔熙熟熬熱熾燃燈燎燒燕燙營燥燦燭燴燼爆爍爐爛爪爬爭爱爲爵父爷爸爹爺爽爾牆片版牌牙牛牟牡牢牧物牲牵特牺牽犀犁犊犢犧犬犯状犹狀狂狄狈狐狗狙狞狠狡独狭狮狰狱狸狹狼狽猎猖猙猛猜猩猪猫献猴猶猾猿獄獅獎獨獭獰獲獵獸獺獻玄率玉王玖玛玩玫环现玲玻珊珍珐珠班現球琅理琉琐琢琳琴琵琶琺琼瑚瑞瑟瑣瑤瑩瑪瑰瑶璃環瓊瓜瓢瓣瓤瓦瓮瓶瓷甄甕甘甚甜生産甥用甩甫甭甯田由甲申甴电男甸画畅界畏畔留畜畝畢略畦番畫異畴當畸疆疇疊疏疑疗疙疚疟疡疤疥疫疮疯疲疵疹疼疽疾病症痈痉痊痒痔痕痘痙痛痞痢痪痰痴痹瘁瘋瘍瘓瘟瘡瘤瘦瘧瘩瘪瘫瘴瘸療癌癟癡癢癣癬癰癱癸登發白百皂的皆皇皋皑皖皚皮皱皺皿盂盅盆盈益盎盏盐监盒盔盖盗盘盛盜盞盟盡監盤盧目盯盲直相盼盾省眉看眞真眠眨眩眯眶眷眺眼着睁睛睜睡督睦睫睬睹瞄瞅瞎瞒瞞瞥瞧瞩瞪瞬瞳瞻矗矚矛矢矣知矩矫短矮矯石矽矾矿码砂砌砍砒研砖砚砧砰破砷砸砾础硅硒硕硝硫硬确硯硷硼碉碌碍碎碑碗碘碟碧碩碰碱碳碴確碼碾磁磅磊磋磐磕磚磨磷磺礁礎礙礦礫礬示礼社祁祈祖祝神祟祥票祭祷祸祿禁禄禍福禦禮禱禹离禽禾禿秀私秃秆秉秋种科秒秘租秤秦秧秩积称秸移秽稀稅稈程稍税稗稚稠稭種稱稳稻稼稽稿穆積穎穗穢穩穴究穷空穿突窃窄窍窑窒窖窗窘窜窝窟窥窩窪窮窯窺窿竄竅竈竊立竖站竞竟章竣童竭端競竹竿笆笋笑笔笛符笨第笺笼筆等筋筍筏筐筑筒答策筛筷筹签简箋箍箔箕算管箩箭箱節範篆篇築篓篙篡篩篮篱篷簇簍簡簧簽簾簿籃籌籍籠籬籮籲米类籽粉粒粕粗粘粟粤粥粪粮粱粳粵粹精糊糕糖糙糜糞糟糠糧糯系糾紀約紅紉紊紋納紐純紗紙級紛素紡索紧紫紮累細紳紹終組絆結絕絞絡絢給絨絮統絲絹綁綏經綜綠綢維綱網綴綸綻綽綿緊緒緘線緝緞締緣編緩緬緯練縛縣縧縫縮縱縷總績繁繃織繕繞繡繩繪繭繳繹繼纂續纏纓纖纜纠红纤约级纪纫纬纯纱纲纳纵纶纷纸纹纺纽线练组绅细织终绊绍绎经绑绒结绕绘给绚络绝绞统绢绣绥绦继绩绪续绰绳维绵绷绸综绽绿缀缄缅缆缉缎缓缔缕编缘缚缝缠缨缩缮缴缸缺缽罐网罕罗罚罢罩罪置罰署罵罷羅羊羌美羔羚羞羡群羨義羹羽翁翅翌習翔翘翟翠翰翱翹翺翻翼耀老考者而耍耐耕耗耘耙耪耳耶耸耻耽耿聂聊聋职联聖聘聚聞聪聯聰聲聳聶職聽聾肃肄肅肆肇肉肋肌肖肘肚肛肝肠股肢肤肥肩肪肮肯育肺肾肿胀胁胃胆背胎胖胚胜胞胡胯胰胳胶胸胺能脂脅脆脈脉脊脏脐脑脓脖脚脫脯脱脸脹脾腆腊腋腎腐腑腔腕腥腦腫腮腰腳腸腹腺腻腾腿膀膊膏膘膚膛膜膝膠膨膩膳膽膿臀臂臃臆臉臍臘臣臥臨自臭臯至致臻臼舀舅舆與興舉舊舌舍舒舔舜舞舟航般舰舱舵舶舷船艇艘艙艦良艰艱色艳艺艾节芋芍芒芜芝芥芦芬芭芯花芳芹芽苇苍苏苑苔苗苛苞苟若苦苫苯英苹茁茂范茄茅茎茧茨茫茬茲茵茶茸茹荆草荊荐荒荔荚荡荣荤荧荫药荷莆莉莊莎莖莢莫莱莲获莹莽菇菊菌菏菜菠菩華菱菲萄萊萌萍萎萝萤营萧萨萬落葉著葛葡董葦葫葬葱葵葷蒂蒋蒙蒜蒲蒸蒼蓄蓉蓋蓑蓖蓝蓟蓬蓮蔑蔓蔔蔗蔚蔡蔣蔥蔫蔬蔭蔷蔼蔽蕉蕊蕩蕪蕭蕴蕾薄薊薔薛薦薩薪薯藉藍藏藐藕藝藤藥藩藹藻蘆蘇蘊蘋蘑蘭蘸蘿虎虏虐虑處虚虛虜虞號虧虫虱虹虽虾蚀蚁蚂蚊蚌蚕蚜蚤蛀蛆蛇蛊蛋蛔蛙蛛蛤蛮蛰蛹蛻蛾蜀蜂蜒蜕蜗蜘蜜蜡蝇蝉蝎蝕蝗蝦蝴蝶蝸融螞螟螢螺蟄蟬蟲蟹蟻蠅蠍蠕蠟蠢蠱蠶蠻血衅衆行衍術衔街衙衛衝衡衣补表衫衬衰衷袁袄袋袍袒袖袜被袭袱裁裂装裏裔裕裙補裝裤裳裴裸裹褂複褐褒褥褪褲襄襖襟襪襯襲西要覆見規覓視親覺覽觀见观规觅视览觉角解触觸言訂訃計訊討訓訖記訛訝訟訣訪設許訴診詐評詛詞詠詢詣試詩詫詭話該詳詹誅誇誉誊認誓誕誘語誠誡誣誤誦誨說誰課誹誼調諄談請諒論諜諧諱諷諸諺諾謀謂謄謅謊謎謗謙講謝謠謬謹謾證譏識譚譜警譬譯議譴護譽讀變讒讓讕计订讣认讥讨让讫训议讯记讲讳讶许讹论讼讽设访诀证评诅识诈诉诊诌词译试诗诚诛话诞诡询诣该详诧诫诬语误诱诲说诵请诸诺读诽课谁调谅谆谈谊谋谍谎谐谓谗谚谜谢谣谤谦谨谩谬谭谰谱谴谷豁豆豈豌豎豐豔象豢豪豫豬豹豺貉貌貓貝貞負財貢貧貨販貪貫責貯貳貴貶買貸費貼貿賀賂賃賄資賈賊賒賓賜賞賠賢賣賤賦質賬賭賴賺購賽贅贈贊贍贏贓贖贛贝贞负贡财责贤败账货质贩贪贫贬购贮贯贰贱贴贵贷贸费贺贼贾贿赁赂赃资赊赋赌赎赏赐赔赖赘赚赛赞赠赡赢赣赤赦赫走赴赵赶起趁超越趋趕趙趟趣趨足趴趾跃跋跌跑距跟跨跪路跳践跺踊踌踏踐踞踢踩踪踴蹄蹈蹋蹤蹦蹬蹭蹲蹿躁躇躊躍躥身躬躯躲躺軀車軋軌軍軒軟軸較載輔輕輛輝輥輩輪輯輸輻輾輿轄轅轉轍轎轟车轧轨轩转轮软轰轴轻载轿较辅辆辈辉辊辐辑输辕辖辗辙辛辜辞辟辣辦辨辩辫辭辮辯辰辱農边辽达迁迂迄迅过迈迎运近返还这进远违连迟迢迪迫迭述迷迸迹追退送适逃逆选逊透逐递途逗這通逛逝逞速造逢連逮進逸逻逼逾遁遂遇遊運遍過遏道達違遗遙遜遞遠遣遥適遭遮遲遵遷選遺遼避邀邁還邊邏邑邓邢那邦邪邮邯邱邵邹邻郁郊郎郑郝郡郧部郭郴郵郸都鄂鄉鄒鄖鄙鄧鄭鄰鄲酉酋酌配酒酗酚酝酞酣酥酪酬酮酱酵酶酷酸酿醇醉醋醒醚醛醜醞醫醬釀釁采釉释釋里重野量金釘釜針釣釩釺鈉鈍鈎鈔鈕鈞鈣鈴鈾鉀鉑鉗鉚鉛鉴鉸鉻銀銅銑銘銜銥銳銷銻鋁鋅鋇鋒鋤鋪鋸鋼錄錐錘錠錢錦錨錫錯錳鍁鍋鍍鍘鍛鍬鍵鍺鍾鎂鎊鎖鎢鎬鎮鎳鏈鏟鏡鏽鐐鐮鐳鐵鑄鑒鑰鑲鑷鑼鑽鑿针钉钎钒钓钙钝钞钟钠钡钢钥钦钧钨钩钮钱钳钵钻钾铀铁铂铃铅铆铜铝铡铣铬铭铰铱铲银铸铺链销锁锄锅锈锋锌锐锑锗错锚锡锣锤锥锦锨锭键锯锰锹锻镀镁镇镊镍镐镑镜镣镭镰镶長长門閃閉開閏閑間閘閡閣閥閨閩閱閹閻闊闌闖關闡门闪闭问闯闰闲间闷闸闹闺闻闽阀阁阂阅阉阎阐阑阔阜队阮防阳阴阵阶阻阿陀附际陆陇陈陋陌降限陕陛陝陡院陣除陨险陪陰陳陵陶陷陸陽隅隆隊隋階随隐隔隕隘隙際障隧隨險隱隴隶隸难雀雁雄雅集雇雌雍雏雕雖雙雛雜雞離難雨雪雲零雷雹電雾需霄震霉霍霓霖霜霞霧露霸霹靈青靖静靛靜非靠靡面革靳靴靶鞋鞍鞏鞘鞠鞭韋韌韓韦韧韩韭音韵韶韻響頁頂頃項順須頌預頑頒頓頗領頤頭頰頸頹頻顆題額顔願顛類顧顫顯顱顴页顶顷项顺须顽顾顿颁颂预颅领颇颈颊颐频颓颖颗题颜额颠颤颧風飄风飘飛飞食飯飲飼飽飾餃餅養餌餐餒餓餞餡館餵餾饅饋饑饒饞饥饭饮饯饰饱饲饵饶饺饼饿馁馅馆馈馋馏馒首香馬馭馮馱馳馴駁駐駒駕駛駝駭駱駿騁騎騙騰騷騾驅驕驗驚驟驢马驭驮驯驰驱驳驴驶驹驻驼驾骂骄骆骇骋验骏骑骗骚骡骤骨骸髒髓體高鬃鬥鬧鬼魁魂魄魏魔魚魯鮑鮮鯉鯨鰓鱗鱼鲁鲍鲜鲤鲸鳃鳖鳞鳥鳳鳴鴉鴕鴛鴦鴨鴻鴿鵑鵝鵬鵲鶴鷗鷹鸟鸡鸣鸥鸦鸭鸯鸳鸵鸽鸿鹃鹅鹊鹏鹤鹰鹵鹹鹼鹽鹿麓麗麥麦麻麽黃黄黍黎黑黔默點黨黴鼈鼎鼓鼠鼻齊齋齐齒齡齧齲齿龄龋龍龐龔龙龚龜龟웃유큐ﭢ﷼︰︴︵︶︷︸︹︺︻︼︽︾︿﹀﹁﹂﹃﹄﹉﹊﹋﹌﹍﹎﹏﹑﹔﹕﹖﹛﹜﹟﹠﹡﹢﹣﹤﹥﹦﹨﹩﹪﹫！＂＄％＇（），：；？＠［］＿｀｜～｡￠￡￣￥";
int chinese_utf8_list_count = (sizeof(chinese_utf8_list) - 1) / 3;

