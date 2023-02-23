#include "DebugFontData.hpp"

using namespace nl;

unsigned char DebugFontData::getGreyScale256(const int x, const int y)
{
  int index = y * width + x;
  // 0～7 の 8 段階で表現していた値を 0～255 の間に伸長する
  unsigned char greyscale = (unsigned char)(((unsigned char)FONT_DATA[index] - '0') * 36);
  return greyscale;
}

DebugFontData::DebugFontData()
{
  FONT_DATA = "777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777577777777777777777610277777777777777777777777777777776047227777777777777777777777777777777777777777777777750377777777777777765775677777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777200016777777777777720000577777776233777777777777777773037777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777750577777757777775057777777746721677667777777777777777777777777206404777777777777777777677777777777777777777777777775016777777777777763777736777777777777777777777777777777777777777777777777777777777777777777777774677777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777736777777777777777777777457777776577657777777777777777775477777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777763777777775777777773677777766777216737777777777777777216777777505613777777367764777777736777773037776577776101677777761677777777777773677776377777777777777777777777777777777777777777777777777777777777777777777776577777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777736777777777777755777777777777777777777763001677777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777773677777763777777777777745777777777777777777777777777777777777777777777777753677777777777777777777777765367777777777777777777777777777777777753677777777777777777777777777777753677777777765416777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777774577777777577777777547777777777773016777777777777777721677777735744777777737776377777500037775374477567777247227777774477777777777774477777744777777777777777777777777777777777777777777777777777777777777777777777467777500057777777745777777730003777776300057777777775277777200000067777630016777600000002777630003777776300057777777777777777777777777777777736777777777777777357777777777300036777760477516777775067777500000026777776200035750000026777600000000575000000002777750003477400167610047720000027777750000005500057400166000277777720277776002400677740027775000477750000002677777400057776000000267777620004577740000000474001677400520027772003200520162025000676000650005761006761000000277777367777777367777777777774577777777777777777777777777777777777777777777777762167777777777777777777777775216777777777777777773000377777777777762167777777777750377777777776027762067777777775320677777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777457777777757777777754777777777777777777777777777777772167777765765777777763777657777426362277247637647777616742777775577777777777776167777776167777777776067777777773677777777777777777777777777777777777777777777657777505750577775100577777625776116776257750477777776127777746666667777603772167751666664677613777227776137761477777777777777777777777777777736777777777777777773577777776257773167772577776377777305777776067772067775057761277605773047776157776147761577763167740576227775167776157777760677777777772277776067773377772477777777216777502775027777657774067622777615777305777216762277761577730677626776116772575167427751677776677416777736761576167737761577763777605777616776037777367777736777777752777777777777457777777777777777777777777777777777777777777777777616777777777777777777777777761677777777777777772277605777777777777616777777777777367777777777745777616777777777776167777777777777777777777777777777777777777777777777777777777777777777777777777777777777667777777777777777777777777777777777777777777777777777777777777777777777777777745777777775777777775477777777777777777777777777777777416777777777777777632133321367616736416725763755777761674277777777777777777777427777777724777777777605777777777367777777777777777777777777777777777777777777746777614777416777765057777742777760577516777416777777202777773777777777724777437775677776577742777772577227777506777777777777777777777777777736777777777777777777735777777357777722775277401436777633277777606777614776047777616760677750577615777763776157777736760677761677516777615777776067777777777227777606774377777247777777720677720277630677766776067776157761577772277506777615776157777227725777761676477516773775167777667760677773777257725765777427775677772277765777457777437777773677777777367777777777745777777777777777777777777777777777777777777777777761677777777777777777777777776167777777777777776067777777777777777761677777777777777777777777777777761677777777777616777777777777777777777777777777777777777777777777777777777777777777777777777777777777736777777777777777777777777777777777777777777777777777777777777777777777777777774577777777577777777547777777777777777777777777777777742777777777777777750000000006761673622772576373777776167257777777777777777777725777777774277777613761672277777736777777777777777777777777777777777777777777765777740677760577777615777772167776147762677751677777523277777377777777751677777777677777467772477777247724777761477777777777777777777777777736777777777777777777777357777723777772277257527255577765516777760677772477216777775676067777227761577777777615777777672277777567751677761577777606777777777722777760675377777724777777774147773027765227776677227777722776157777506722777772277615777722772577777567667751677677516777766776147776577724772476577761576477777516774677767777616777777367777777744777777777774577777777777777777777777777777777777777777777777776167777777777777777777777777616777777777777777616777777777777777776167777777777776777777777777777776167777777777761677777777777777777777777777777777777777777777777777777777777777777777777777777777777750677777775677775677777777777777777777777777777777777777777777777777777777777777457777777757777777754777777777777777777777777777777775277777777777777777653666556777227367777247525577777725537777777777777777777761677777777616777772027372027777773677777777777777777777777777777777777777777774677772277777227777761577777647777615777777774277777626427777757777777772277777777777777557777416777736761577777227777721677777777777777777746777777500000000277777774677773067777227616736725547775661677776067776157612777777777606777721676157775677761577766776157777777775167776157777760677777777772277776066267777772477777777522776322776650577667614777775067615777751661477777416761577772477227777777777775167777751677776677722777567774276127667777416567777761476377777777735777777736777777776167777777777457777777777777777777777777777777777777776200037777616500167777751003777777500151677775000377772000000277777300032067616500167777400067777777761004777616761002777776167777205203610476326500167777750004777632630026777774003756773204750037777300023777400000027750167750167500057720161016102720162001620027610047500057500000016777777745777777775777777775477777777777777777777777777777777527777777777777777776577745777761016777752724467777772057400277777777777777776167777777760677777751133267777777367777777777777777777777777777777777777777776577777227777722777776157777777777751677777775267777735742777764610037777226300167777777736777772057744776157777722777772167777777740577777735777777777777777777777777736777777777614761652773654777367247777606776357760577777777760677774067615776267776157773677606777777777516777615777776067777777777227777605127777777247777777755167542277667227766760477777605761577772276057777750676157773167761057777777777516777775167777667775167746777527612756777761347777777427367777777763777777773677777777725777777777745777777777777777777777777777777777777775057772477761347741677740577227777416761167774267732777776167777777227760436761247732777777616777777777772477761677636777777616777772166037616741347732777721676227774125774167772267621677651443721677337762277777616777777616777616776157776167616760677377750677457777227776377752677724777777762677777777577777777626777777777777777777777777777777765777777777777777777557775677777720277777302646105776206774377777777777777777616777777776167777777752677777200000000677777777777500000000277777777777777777467777722777772277777615777777777762677777720167777744774277776247772277721257730677777754777777740005777722777750277777777777777775157777744777777777777777777777777776167777777613776164476165477647742777760000047776057777777776067777506761000016777610000067750677777777750000000577777606777777777722777760020677777724777777775506745227766760576676057777760576157773057605777775067610000377777740037777777751677777516777766777605764777761653165777777406777777760337777777773677777777367777777776377777777774577777777777777777777777777777777777777516777427776047777247760577741677606777616776167777257777616777777606777427776157776167777761677777777777247776167637777777761677777257616761676157776167751677761577615777724775167776167777225777777736777736777761677777761677761677724777657772577257657777227647777752777557774577722777777753677777777757777777776157777777777777777777777777777776577777777777777777745777467777777202777777756256166372477457777777777777777761677777777606777777513432677777773677777777777777777777777777777777777777777657777772277777227777761577777777773677777777750477763777427777767777615761067777247777773677777755750067775037753227777777777777777777777777357777777777777777777777777367777777525777616257637557755776167776067773067605777777777606777750676157761677761577736775067777666775167776157777760677777777772277776027227777772477777777561573622776677227667605777776057610000167760577777506761574277777777750057777775167777751677776677772475577776164516577777750477777777205777777775377777777736777777777735777777777457777777777777777777777777777777777777777777632777616777722774277777777742777761677427777724777761677777761677742777616777616777776167777777777724777616626777777776167777725761676167616777616772477777427761677774277227777616777722777777772377777777776167777776167776167775167746777427604756777761337777777367736777777741677777777626777777775777777776267777777777777777777777777777777657777777777777777753455525577777735027777773616725427516756777777777777777776167777777761677777202637202777777367777777777777777777777777777777777777777746777777227777722777776157777777773677777777777606773777742777777777772477227777742777775277777742777731677750003612777777777777777777777777774677777750000000027777777467777777637777761625742746772000005777606777722760577777777760677774167615777467776157776677506777300057516777615777776067777777777227777606750677777247777777757226472277667760466761477777605761577777776057777750676157615777777777730677777516777775167777667777227467777725361557777773406777777751677777776167777777773677777777775277777777745777777777777777777777777777777777777777630021277761677774277227777777772277776167740000000277776167777777227761577761677761677777616777777777772477761520577777777616777772576167616761677761677257777752776167777527724777761677772477777777730047777777616777777616777616777615763777763750273677777605777777742763777777760577777777774577777777577777777547777777777777777777777777777777777777777777777777750000000006777773651677775561672424772473777777777777777777725777777775277777613761673277777736777777777777777777777777777777777777777765777777722777772277777615777777762677777777777761475000000000677777777227722777774277777227777773677777247777777760577777777777777777777777777736777777777777777777777357777777763777777252561263777377772477760677774066147777777776067777227761577777777615777777760577776067751677761577777606777777777722777760677227777724777777775742557227766777215677227777750676157777777615777774167615772277776777777247777751677777516777766777750537777772357235777775572277777775167777777347777777777367777777777736777777774577777777777777777777777777777777777777603777427776167777427722777777777227777616774277777777777616777777761000577776167776167777761677777777777247776127416777777761677777257616761676167776167725777775277616777752772477776167777247777777777750057777761677777761677761677774274577776163505377777750277777776164577777761477777777777457777777757777777754777777777777777777777777777777777777777777777777777534555255775057366167777466167242277503577777777777777777774277777777247777777775067777777773677777777777777777777777777777777777777774677777774067776057777761577777762677776776267776147777777427777406777724774167777427777722777776167777722777777775167777777777777777777777777777367777777777777777777357777777776377777742601611677637777427776067777506722777777567606777722776157777766761577777777227777606775167776157777760677777777772277776067750677772477777667576016722776677761267722777774277615777777772440057227761577605776377777742777775167777751677776677776135777777405720677777377506777777516777777637777757777736777777777774477777777457777777777777777777777777777777777777724777742777616777722774277777777742777761677427777777777761677777761677777777616777616777776167777777777724777616772277777776167777725761676167616777616772477777427761677774277247777616777724777777777777760677776167777776167776167777604267777723361047777764614777777724377777772277765777777745777777775777777775477777777777777777777777777777777777777777777777777774677637777406736616777657616725427772067777777777777777777616777777616777777777506777777777367777750377777777777777777777777777777776577777777614777416777776157777762677776577206777605777777742777722777760677605777724777761277777725777772477735777247777777777777777777777777777773677777777777777777357777777777777777776167777756755777760677606777721675067777647760677740677615777774676157777777750677760677516777615777776067777777777227777606777227777247777746757612772277667777405776057776157761577777777503750525776157772277725777772477777516777775167777467777720677777750674167777557772277777751677777735777763777773677777777777616777777745777777777777777777777777777777777777761577774277760677772577606777765775167775167760677775677776167777776125677777761677761677777616777777777772477761677605777777616777772576167616761677761677527777725776167776147742777761677772477777776677777257777616776677606777516777772047777774047206777773775167777775047777774167774577777774577777777577777777547777777777777777777777777777777720677777777777777777367764777760573634777756772561661377502665777777777777777772477777744777777777777777777777777777775016777777777777777777403777777777467777777775057505777777504777773566666257750577612777777774167776157761277772057731677776027777776057773277760276227777777216777777775157777777777736777777777777777357777777777730577777750577634772577776147760677730477720577526776067730577761577762277615777777777216773067751677761577777606777777777722777760677750577724777732775772277227766777761577740576227776157777777772277202777615777505772037773377777751677777612777337777774277777776167527777626777605777775167777753777750577777367777777777774477777774577777777777777777777777777777777777777226774125576036773277772167753777722775202677405775377777606777777752210016776167776067777761677777777777247776167774167777761677777257616761676167776067772267622777612676227776137751167777247777777605777516777772477467772277520267777406777777606742777773577722777777616777776067775067777777457777777757777777754777777777777777777777777777777772067777777777777777737776377777620005777774777610577610057302777777777777777777626777763777777777777777777777777777777761677777777777777777740377777777657777777777750005777775000002776100000006777610004777777740000277763000477777750003777777612777777763000377777500037777777721677777777405777777777777367777777777777557777777777773057777777610015772005776100440000001577777500036774000003677750000000047500047777777773000577740006760004772000002777777772277750005760004600000000272027456100220047777457777500047775000477777777750001677600047761047543000377777720004777777300057777777647777777647765777400277600047772000477761000000067777736777777777777637777777457777777777777777777777777777777777777773000561167656100377777750003777777300352577775000377776000002777754777773276000675000577400000477777777724776000575000577200000277200520161025000675000577740004777761630037777773003516760000016777762300016777777610167777610035257777763777777763776377750016720016777773777777200000016777777745777777775777777775477777777777777777777777777777777777777777777777777777777777777777736777777777777777777777777777777777777777777776377773677777777777777777777777777777774477777777777777777777777777777746777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777762677777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777614777247777777777777777777777777777777777777777777777777777777777777777777777777775043777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777773677777777777772577777745777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777772577777527777777777777777777777777777772577777777777777777777777777777777777777777777777777777777776167777777777777761677777777777777777777777777777777777777777777777777777777777777777777777777777777776577777777777777777777776367777777577777777367777777777777777777777777777777777777777777777777777777777777777773677777777777777777777777777777777777777777777765775677777777777777777777777777777775577777777777777777777777777777765777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777775477777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777760477327777777777777777777777777777777777777777777777777777777777777777777777777777730577777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777200016777777777527720000577777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777405777515777777777777777777777777505773377777777777777777777777777777777777777777777777777777777777616777777777777776167777777777777777777777777777777777777777777777777777777777777777777777777777777657467777777777777777777777750577777757777775057777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777500037777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777761000000000477777777777777777777777777777777777777777777777777777777777777777777777777777775100025777777777777777777777777773000477777777777777777777777777777777777777777777777777777777777500047777777777774000577777777777777777777777777777777777777777777777777777777777777777777777777777750057777777777777777777777777777777775777777777777777777777777777";
}

DebugFontData::~DebugFontData()
{
}
