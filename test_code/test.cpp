#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n,i,j,count=0,t,mod=1e9+7,m,k,tx,ty;
    vector<long long> ans;
    cin>>t;
    vector<vector<int>> dp(1000,vector<int>(1000,0));
    dp[0][0]=1;
    

    while(t--){
        cout<<"\n======\n";
        cin>>n>>m>>k;// later-optimize: by taking max of x,y dp matrix
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(i==0 && j==0) continue;
                tx= min(i,k),ty=min(j,k);
                
                for(int x=i-tx;x<i;x++){
                    for(int y=j-ty;y<j;y++){
                        cout<<x<<" "<<y<<" - ";
                        dp[i][j]=(dp[i][j]+dp[x][y])%mod;
                    }
                }
                // cout<<dp[i][j]<<" ";
            }
        }  
        for(i=0;i<n;i++){
            for(j=0;j<m;j++) cout<<dp[i][j]<<" ";
            cout<<"\n";
        }

        // for(auto& i:ans){
        //     for(auto& j: i) cout<<j<<" ";
        //     cout<<"\n";
        // }
        ans.push_back(dp[n-1][m-1]);
    }
    vector<int> v(n);
    for(const auto& i:ans) cout<<i<<"\n";

    return 0;
}

// =================================================================
// //unnat hackercup round1 a1
// #include <iostream>
// // #include <bits/stdc++.h>
// // #include <iostream>
// #include <string>
// #include <vector>
// #include <algorithm>
// #include <sstream>
// #include <queue>
// #include <deque>
// #include <bitset>
// #include <iterator>
// #include <list>
// #include <stack>
// #include <map>
// #include <set>
// #include <functional>
// #include <numeric>
// #include <utility>
// #include <limits>
// #include <time.h>
// #include <math.h>
// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// #include <assert.h>
// using namespace std;
// #define nil -1
// #define MAX 100
// #define ll long long 

// int main()
// {
//     #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// 	#endif

//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
    
//     unsigned ll t,n,i,j,k,sum,x,casee,ans;
//     int curr,nxt;
//     char ch;
//     int flag=0;
//     string res="";
//     string tem,s,uv;
    
// 	cin>>t;
//     cout<<t;return 0;
// 	casee=0;
// 	while(t>0)
// 	{
// 	    t--;casee++;
// 	    cin>>n;
        
//         if(t>=0) res+="\n";
// 	}
// 	cout<<res;
//     return 0;
// }
// //----------------------------------------------------
// /******************************************************************************

//                               Online C++ Compiler.
//                Code, Compile, Run and Debug C++ program online.
// Write your code in this editor and press "Run" button to compile and execute it.

// *******************************************************************************/

// #include <iostream>
// // include<c++
// #include <bits/stdc++.h>
// using namespace std;
// int solve(string A) {
//     int n=A.length(),sum=0;
//     cout<<A[n-1]<<" - \n";
//     if(A[n-1]!='0') return 0;
//     // unordered_map<char,int> m;
//     // m.insert(pair('0',0));
//     // m.insert(pair('1',1));
//     // m.insert(pair('2',2));
//     // m.insert(pair('3',3));
//     // m.insert(pair('4',4));
//     // m.insert(pair('5',5));
//     // m.insert(pair('6',6));
//     // m.insert(pair('7',7));
//     // m.insert(pair('8',8));
//     // m.insert(pair('9',9));
//     // m.insert(pair('',));
//     // for(auto& x:A){
//     //     // string y="0"+x;
//     //     // y=y[1];
//     //     sum+=(m[x])%3;
//     //     sum%=3;
//     // }
//     for(int i=0;i<A.length();i++){
//         string y="0"+A[i];
//         y=y[1];
//         int a=stoi(y);
//         sum+= (a%3);
//         sum%=3;
//     }
//     cout<<sum<<" = " ;
//     if((sum%3)==0) return 1;
//     return 0;
// }
// void solve(int a){
//     deque<int> q;
//     for(int i=1;i<=a;i++){
//         q.push_back(i);
//     }
    
//     while(q.size()!=1){
//         q.pop_back();
//         auto last=q.back();
//         q.pop_back();
//         q.push_front(last);
        
//     }
//     cout<<a<<" -> "<< q.front()<<" \n";
// }
// int main()
// {
//     // cout<<"Hello World";
//     int a,i;
//     for(i=1;i<20;i++) solve(i);
//     cout<<log2(5);
// /*
// 1 -> 1 
// 2 -> 1 
// 3 -> 2 
// 4 -> 1 
// 5 -> 4 
// 6 -> 3 
// 7 -> 2 
// 8 -> 1 
// 9 -> 8 
// 10 -> 7 
// 11 -> 6 
// 12 -> 5 
// 13 -> 4 
// 14 -> 3 
// 15 -> 2 
// 16 -> 1 
// 17 -> 16 
// 18 -> 15 
// 19 -> 14 

// */
    

//     return 0;
// }
// //--------------------------------------------------------------------



// /*
// class Solution {
// public:
//     string subStrHash(string s, int power, int modulo, int k, int hashValue) {
//         //brute hi krte hai
//         int n=s.length(),i,j;
//         long long int pwr=1,ch=0,prev,lastpwr;
//         string cur=s.substr(0,k);
//         for(j=0;j<k;j++){
//             ch=(ch +((((int)(cur[j]-'a')+1)%modulo )*(pwr%modulo))%modulo)%modulo;
//             lastpwr=pwr;
//             pwr=(pwr * power)%modulo;
//         }
//         if(ch==hashValue) return cur;
//         // cout<<lastpwr<<" ";
//         for(i=1;i<=n-k;i++){
//             // cur=s.substr(i,k);
//             //cout<<cur<<" ";
//             // ch=0,pwr=1;
//             prev=(((int)(s[i-1]-'a')+1)%modulo );
//             ch-=prev;
//             ch/=power;
//             ch+= ((((int)(s[i+k-1]-'a')+1)%modulo )* (lastpwr%modulo))%modulo;
//             cout<<ch<<"\n";
//             ch%=modulo;
//             if(ch==hashValue){
//                 // break;
//                 cout<<ch<<" ";
//                 return s.substr(i,k);
//             }
//         }
//         cout<<"1as ";
//         return cur;
//     }
// };
// /*
// "xmmhdakfursinye"
// 96
// 45
// 15
// 21
// "leetcode"
// 7
// 20
// 2
// 0
// "fbxzaad"
// 31
// 100
// 3
// 32
// "kfedcbdngvlykqyrbvwbnaassgjifjxtawlafhcpjtpzfnbsqfasohevbbhkwmtnmixolfepkjmcbadqcljmsbonrngsgfqwzqiisbiwiqgtqtqddukgtjymbxzmtxrobuhkdxmdmqccrauzkrjisstznnkhupiandekzcchsrzwintkkzhvqomqmnbasynmvtxwydcvwoukqmgrpmgzqancuzapgncasxnbyznlrdvcbomdptjftgxdzeqzyavfdpseoxpvohpxtikyjfvskxyqbubgnseraxtrcrwjxloxymhqgaxwbbvzhjsbncqrlpdbiuakdjzjrbclhxgnjjyfrqyjchlsdrcwtdoktviqwjctlmzqemumgmjufcbixkfhzkugsvnkrrakccguybwhmuexiemqusltaaqrswsezccqzaputgaabrjdeihmkpzbojnusmhkwjdxvgiexwdkkazhhmlalgzvxgqgncfytrxuhkwhwcxhmlbvkhjcnyztepwnlpthozdqexvhxpvheopjrsjzkqrstczffkhkikelwydcbnghfiibeyabgegdgaqvasujmggltkvokmnsmontjzsmzoeeqenafvurbnbwqbizvaqxfgnoxasctfrwvqmoufvpajdkethlvbhbehxahcpcizocbchwfznhuqtblwepeqdhycrovqosmxxeeqaffjvvclmpcqdugndexexcykyusetuamymszlteobxkestwbzubpstbwrstuovlybycevedzgurqvlgkouvavcukccgixixsrndurvrkfegegnchbhockujlafxexlxhgysraviztkjymiqxrlldcixvfnzrpserrqycbfmesqbltywmandcqtluccbisfqzosbvedqhsxepdjevaasylvjmfpvyxqvclaalgxytiukyarojmzyovmiunkvqhkouhxxhbemavagrhteofpowvlpdunjjpwgcjibagfswrzwkgrwklppchvtukzncvoqorlsskyghkhrazwvyqqjfygmduhsfkrseddgmtdvlqeruxogmyttdqmdpmscspatkoifauivwjtbwisiiqztrllfqnjvbagrfylrpjudjmvwhdkhahyxlsfbkuuyofryfgblllzeacfiqqawridcbtqnroxwuqhyspqmwhxmjztqokofnkfvupcykszthicdgjbrgafpztktrcwtayoulnjaazigkinnpttghhyboiczvtswenshlmqyelnwhzqlswblqssiiynypfcxerlykpiyimkoodimdfdlzbwmlwflylcqwaflivqeonjswvowxgeoafmppodmfbvooodtnzgmhfnchenaaywqevklrpgajbmbxgiopofghlouhjfarjxlclcullsgyzhohowtragbkaebrvbkmxfxughlirtikheojbrrgxtqldfdnqxndzvfgajiltnqnuwavxbrvuiycsizunlglwnivpseyfwmgydmmpzhxkdtpuzpddacjmjhvncdoicedkimdgaqobdfagpggvjemstqbsshynyvhdyslgldvkapqgusmnuroqxcivjifkhrotomxodficktxmcytkbqitrlalpbtphowfgtzgfacabjodvivgykorvmxhzpqvskolkbfpbdgowlighossrlwiomgohfhgklmlnekniqfjmvvqvmimkeddfxnxwzzroospxvndynetghkgrakuslukqsrdtmjkblwrmwhzzojcwwogrjvnftdwwpoqcjqimvjbwgqgpeffjnwlzdyhkhwmvpwpcmjmdqneexqwcrvdxsfsnidwyflwxwngczklprhoazeeqwclrqvnicfvrtbqailbwrqxadxslouwdjycidupemdwhpkqekaxxprtdtmjficrhlvqidvgwkllaowyyajkxugqiztbpzvjqtpuyugkvdfcaczzruskvucsxtvroljnjojuzncatgnypbzwvilbajqqnjovqxcfunwwbxgshrjlajwveaswqegidfnedpxqdreddvawrpbllkcshlafnxyocbmwacytvgtoonlkukqhxwbfxcfnbgmrfcnkvtxmygiyjoyoljd"
// 71717
// 94536
// 1149
// 39999
// "agpvmiqjlwfwcsqrnrevjbipofxfqbruberiofptdwgvntnrwalbuejgermmtfseqbqtmlwevictnzmoucyrwxdcssdzncbqwusscnolefuesqhbvtfwrbdquzzzhaqqpgxqagztvzwjeuplipdkrhqbridopdwmqeucejsmdyrsmsiugvfiqgzyzksddfbozozvogjtxcfblqymnggnqyvseypfhprdreiasecynkuktfychpqrttxufzekyfbguxsfjsmdvlfyozjczffumbelrysjxtkplaotvnikchjapbttwfrtrsipzmvfsvuumxmlfuxqscywksfnnjcrhlkkhmxgatrommneaylpfthdcmrpjudwjbsyzvsoptjmkjyrbcmtbfgpldmqspztypsoyqapkrlniekezushegfgauwitxopadbrfodvnufemobgysuezzzplaqvaufnltztkmoyuocmhlfufcssukwjiiyxbcldhumkqacrqivnkpzawiulbnoxxdntnoofiymbxljoynlgaiwffmcmolmumvqxqyvdrycidmazpthdmjtznlkhsyeyiqeekhyseovourxhcoqeoobmjypcdzhciiyllipdbswsrydeupsklstabkcgtdwsczihpetsxzkcifvcrtzjsemxsozzcazhzgucptmlgrolvkflrncdqjiwfnejsgqzzjzdtwmnwlradwrmbwlzgowcehxbnwibziximfzmkpeunbqeszgjvbfpprmpzrkdyjndduxvosjzdlidpkreewzntwywtutakdvexosmowwlkrwuaileraztxvvvhhypeebltueqdzqjgfcohycatymeppohshaitrplwdsbwfacqhbpkqcsyallnzqqnrkxznbqgocuxczzztyuwqwjduvewxdxdsvrnufybtxautheovokvzmvxjsbxhfjteqknvpfwtmgpnhigfykxitcurmxljhzflvmrpztnnokejntplmwpayoltgomxrxlieffkewweneczgtedjkfnzqyawqekgsmrncjqegedxpodvqagrsudytspbqcoznmqldgtyzrqjmfzhqdhflcbgudzokoeczofkalvyojjvhxvwqzgirdweobzztvgtpovmgxbzxwubdjgaukbhkyqefocvjomhybyaxzmpwbjgduqclonlnaiknglfujqinpvvpkxvcbidqxpzfjbenlwlbuthmqghwtfwxceznjzouvuzsatowaatoraixutywqykgcvdxyogmaoehiigmijowyoxdcxipgcbmswhvwsdjshlzfiudqdcifjfvocwthlykidfiknblviivltbmfdpisyquqoirnpgiqvplroddrfkdwftacjvxywavujynwiqmduhawbenxgjqwgqydpzsubjxijrdukwphwrdcvrkqvgfmxchkujtuultubrscrrunhlugakvgljfcmzthjfsmdktwtscooajqujfijsepdycorvgrdhhuoluwawcyfiyhynagelriyjtokiwvzeshqxqhvxhrgewtrjuaicszflmyzkpnsqopoyplwakiijldfvhzkpkdisemfnzvwoyicgbmhfiiohuzhjcobpalyeomxtktroefzzwebiiqxroiyslxmslhetapfmvwamkqretcxbmizpfhusibczcysdamqqrljjvexkydlsmofcqlmutrcwmzvghqohnrtubyhaqrckrkvvtqdvtpftnuntmwwobzngudenktufuigghdpyjtmenuxwmhvqcqjwdtnxyddlpcukhpdgqchzynpreyaqrtyxeaeqkblruwiyovnukvhxtjpunejnzllluvypezzbimdruuchznevubvpbmalhswlybfwlowuenofdversfrgrcpcfujwntavhcenhtkztvyxqdejigiogxhknimbxzmxclxlfdqlizskknyqqomnblbymasmzrfqrqwobbzeermtwhikkyrtrcwxexmpltfyqhblawfqschrwhgxiotpnvmqdihnqnepdskyhamtuubuqusobuscsysbsjvdexcvvnpluyetqjelvqlnglozojhbpnufkcelaozqfoeacvjiaqqokxfolmqbwpksykhmgcofxognnmgwxcuvifhkdbqwvgkgpsjrmuljjldslbevkrbxducjulrzljpvncndcaldujtuwwapvztemimlgtcwkyrsgkodycnqckgxzfeyuglbhngrmacutedlcpyunxaxnltvcjiijcsalefglahyuzrbsquewduvimmapomokabpzquwbwutbprxsbdgsvolzluosfsvxexzusglylhhlsjaxddzekvridroebldovnfbqnbbvpnhxbozravopalroaqkxdsteqfbvhgkpcmaqssjeqallpecpvwtpqzinohufqjgpewuxudnvojmciyxmziqkdbtaeudpyirhwgopyneeoeoiwoyhdrjzbwmluzbgmduohdctqcjdrmepgqylixlenwisemxrevmpdfeywqkcpqyiburuxfznftxintysstimtghfihenojkewjkutlucxtlwsxdedamsbwqvvilexswiawcmrljhbrbdotfyjjfexzpdvihjbxsrgashcvoyncjuvceitoereqorxnlqtsomgmdshgzwktgogfsvyxztfcrffdxtpcobyncebqjwxxvdtmrwzeovmfqohrqedreublylwjrhyqpuevrgffexnlwctenvtfqlkfexnikjmxutnpnwxowdudjkqakdmfqrfolwmzqjxfxmxnbovcduebwvywhwtldqhniltgobckmdoslobpxopnufaqftufagzhacsiceifbmgoxkhhzpqrldoeihaxgaiveaoiixyjrwtdkkvqnpbaagzjakozyrotxbhznrwjdlzywbrdnvhqnohegyxpwhdvdksnzzrvkqirpynvuaxgkabruqfdksuwcwqwsgltprvnaqopmvvfsxbursudfmjnfuiqrkyybnflqmvgcydorlytxflvkuxeartbcggmgxugvndnsecvemjdbtedjpmffdyiahgicdwpmzcwdtuzdxspdlinezsoullnoiqlcibgwlklwjsullpgwwmqshpekxjzligaszgpuwcqvtkzjlenuumyxlgevyynxvnionxkbjkfrfykzmkaasonbndelesuxumjpplgsrtqajvyxnkpkfivhlyoycuqppvjpirrshyqacmqkfnxihrwftvxyphybevhzwptqtnkucxravsmkooooicnabhrhxntzwafzslifxoedwdutgepxprcsqidbpxsberuuzsnjupcssnkwjlxelwzrtenvuccztgnlkixslaglkuubezddzonhypccbtupxnzqmogvcilfyccpalhvjvmnhtjieiitjeghstpnxfbfsgkweowczulksebpnlhgiqszwuiigrasnnvbarxxqkpkdvnlmnfbhgoismfibasjydtehaeodbnozqhuwpzutkgowiunjpnftfmjncbdupydmnephtlxvkrnvbxnsczgapknsqpujlhqckwrpzwizbdauggnqnulvxogszvgeyjzcmfroicojbxuxxzjphbcshjnibjxintihizugnykrhnpgrhocmqrxtpcbmiqkpzceojawocsfszqlvkyzrrvmenokfuiuberjqrdbqglqpaunsdicmuehfueclqwfhdtkqfyfdwlmjidakngjcbaaylqkinoowdddwhzfpfojzuavzkhojfrdhpljcqlsvzzxsjlafownopesrpnjdexzfkbuwprdaqtywjvfrxsuxbppmseituwurqtlnoerauaawdsasyamnlngtpujzajjmzzvhbgitkgcsipkbusteizalrawwzypyvwgvtplhcbksidtsgfwafqcysmuccropqqoofozreanekxnsgxmvkruwcyrpgdgrdqagderphlxziyzpybqhomribvywmjoarryptcylmvzckweqjtjfxthhdsdecjukvljgalalbrnkenciqpnvzvqfhnsvavkwqotjherjcciilokfaibesztjiuwnfvooammmziyrrxptqbchvohfumchomqpnovzdynwfvjyufnqhzqpjznwkbugtvxxfzrthtrlytktfptzgljrhfbstyoeaccavetbjhpfowaywcidsteliqwscbpodaqjmvpxzojynrhnjvfqjuksorccnnlnxtyfjubihtmejkhuiarffakfzikveocqkfqdcmjsnwxetufeerogsxlfophnbeqxmkfiwjlegyiwcekdqwssljyojbkfekqqwmhsdsrwoemalqyjmtnxcqtkbbpdqvvweadmsexazfwwbtvctpptpocvzpvckhdfgihqbrgqckarhfvgowiklilhhzbqulhrqznylanisgzhvdjepmysoortmgkobeekdwczsteljngbuiujoemdwgwhebhhnqduidbroyouhwyrrgjiwnnpookvoztoqsngsbbwpaigopkqmrqcitpzmcyriglfisddisbuvehlpegjmvrqtojufppmotvgxmabxornxkwjzcditnwjqueequfnyrrqisioxbrjeihfviclswmnhcrkphbwhpwnhddyxteynxpxvqtpknlicuuzwqlmqckvprhwlndtzmswrvfqflsmvemwxbtznobmyddfgcpupsjwrlpkevxfinbnrjvumbbvolcpumrvvfqkvbmclmdyswrnhhkyptxweebjlbqoizudxbecxkzehaedoiheijixyzfvbjmgcvbelrukipzivyustzqaipklcwlpdlifcmxcsdiasjblnuueytjyqkqqhlfieljacocuzzlyofkginxkrlbhltpatakfzbdozzpkbfdhoffiapexzesxopykcagzqhfbtlnuyzgjkbjwvtlbfoebakmrfwnetqmqkeisooyhbscokxukpurxzhwfjcouhmkllzaxszqezucjcpnggthjqamkbangqpteverodpjtzwuvdjwfsoglabebebgzounviwkntfmrrwhvwddwtkrxzjpezcbvnekseceuupjifgrgnddfdpucfnblydbgxdsunvixlneenzczxovspauufjpbohatronibvowiuzsypuhkiahkyzkxkaptwxygjyrwrdgmsoojnauyzobkqrtlndwkyqjuiwpthgsopvserxsmywlzsbfswmixavkffmboitudbrcbnzoxfmravycfasuxpjiyrgaluasdnkufhlpkdvfwdpsfaujxxkkspdujlaaytiabikymquhjraxdmtupsiqtprtnfpuhescwpwytawwfrqyuswexlfifpnwfkhtxwampqhznhjmpchuwnpjbnwweosvesohmwympwnvnznfaoqjilirymffidqqtgeazufivfjrwtefvipezbwlcidrookxlqnnyxonxzivfsthinjsszhqtwdykngkvbyitfnlwjhdxfbloynfyubhyiemiyeffwwdknoizadwlavqizioqnjwatqhyulvawfpwsgxnsditoetrupnlhpmuwkkjlcdyhmganzxrmfygmbdcxbwbhetrmocwvhlbicpimdtbuhnjuxjysfdhylhlyjzjfnxdbzlbjgbafxaykdbehmgdzryouzizhbudyzpykjnbqmymfmefxfemnoazamarchblminrkjsgmytwvslforczzktjxtdvkhedqrpwhbxxtpwvjpkowvyahqeltjwnyabqxywdmhehheoqlikftmrpribdkxoxlykowqrfqdeiaqpcozzchyhujtgcibkawcceifkeoilalferbegfpqezmvunyygvhacgjdpjttrrrcwemxyquxefmscttphileratqdmlekeckwauocqsuwtzalxlesrbxenknpqdhvopbzjblvievoajelotsmbplssiqpewpcndfhgzttidzrphswdxrgmxcwnrrmukerexkgrsojjipmpkcqswchgjbfrqdeukldstbvsdwgwrmnhnhwxngooiibltaiwfvlalkskjhrxosvbltjthagsewysoabtuzccyoszkqadvnjoidsnspyplbgkcvidiimgmmntapwczphqcrrqshvyciwdozbbaibfqtpykkgngqlwpvcjtcjnhoxzrjdnxeudnfuajsvkhttppemqzjzyeslhgcadslluwhatyzdwsnupkwvoxcwhxhvncmajbzflxkddjlfunrwnpudpuphygzoxzpwmmnkpsavwyocawolusndclbwwftgahscljdzrvumazdgkjthrmxcsjunrlmkrroelzkvjbexcmdfuqzcardwelwyfzetuuqvsgaxgjepcfmmjnhihlpjxnabwovtwmflrptvzrupulchwsfnwpjnzgehszpupqiqpfshanexncrzrtnfzzlstydjinbabilrwegsxoppstjvypczmczxkmyetxwtdcwfhaxsiquqqswbrfkkrantwgcbdfoyspagebzybjhcygmlcxjwfdbyzrzuecdexsakmxvpuiafluttobuwuqbgtfphhlbzwqpfbixeywuitgpvbzotevszlsoaipaeuthrufseanqxevurlsdeuedvhlyyqcavimxszdrrzlhfualolytbohxaviocwncsrdsqifdxxorpaobjowwhbispphygmyxuriogwkpkjjuctdaqcykfivccognnlddkdntwkmfxsmivowurxpaogedjhsxrattfqqfrjngjentuyqzfpexxvfhivuemwzknqichxzxphbnuzhofnsjcniyzelrefduhbywpxuqjdgzsgwuhurjfrsihusbrwfoaawdhqhqenlbjmebpbxwqoxyswigskwpbubuwiqgtzciwzbnvuarevzcxqjrqwbzmsnkkaswqosrlharwcpdtctvytwnbtjonocbqqnzwhjapxilhgkigxfcjlczigjptpmoeusyvwsfwhupwccpmyarribhjduahizeijhrwjsateifkibggannftqilokpdpjsvlkppvzcsbivistoybcfldpvmvbybpkywvgfbzttmlgaeizxzexftaoytkyfpkyfuggulsnildnuwofmkfnaxqoyzqqxfimedfazfmpglqrwqxxjlchhstoqjeqogxhiqhebuhqjuknsfnuozugwmhkurkncpjlcnqdrfjixfeyhojuktiwvtmehudtczuonqlfrjhyjdjorijwnzwvpsxvjjsierjzpjeyqmndmafiykfucszxwkxdvoxujkzyngukkkehaebkoahjdhzwoujmaqburqnqulzflcnzgagqhckubzmenputjwuvupbpbiogceshidshhuodxrzvdrjpwrgtnctykfjaransprwgkomcjnnwjvtkbnfbvsfcfcxddvzapdzyohlwhuoajkyhwtlntoqztabelfmsrcdyklkiulpphhzkvgyoqqcqjawvaejeybdoaecvzibfgffqwabtthxcmnlqewgpndcripwtuisvynkjntrjwldiozesbwouuobuathtsyuvcxazvrdafbgtediiqolyhiutibuvwnmigoltospcyxkigdfoqrfsbklcbkdjowmvgeufvnhufeeaurawzkuytnyllshyglclzqjjgaupukhrrsicissyyqbyrdlsgwjmqrrfoxkuyhcqznmsdxvjwlpyruytogeamkywqdxtkxnffpvpvoxjaqeeufjdqkeatletwgszuidqdlaaogtipackdiklfgyyuznowsqyzqskacfrxejmztnozjbvypfrzteeisvzjwfhoujkkobkjzvpxxylrcqvfhbtlnayvvibxeckcrjyahfdeingdirqyvppufhsebehiqnafekkxeymakybcnvrjvmxfhfvhzbhdvgarhhinaxeyyiermebgsiadrotjoaasjhlhxrijbdpwbtvxngpbejaxvxgnpjjkstagpvqepnyoanwbswwoejexmgdqrluzsmedtknjcqdpghelgcolkgcdcjgibjaltupszmojocjbdyqzzeihacgzmkrumgeeusldoeahgrqpctpiimxowjrxehbokaafdjrcakrrabljkoxzdiwbamaxzhagivkuvokddssshevoydzhgyqwjqredoxzgqpnlmtijszwepwnlbakioprcffebyljijzigjhkhvenhwgmzdtepnkmfzyapcwuecuqxxzbdqpnukjrfzcfuwmmnzcwczvhwlndwhamnyquajkvjdzpbkbdvfbhskbffmownryipzdujmvteoxjuktxuyoftullfliqyljssrbmlmjmvzkqajdwptzxegdopxdblxhiikxgykqrqjlkaqcaytwtpewaemqmroqbucouaimbtwzxbaimdhkbnpaprwacdeexkrrbauuvhkgmhxtvcnzbdcggvraufreyiwszakdnypnvcmjimqfcyitzqmtvoqumjjhpttrzrlewwqomtuelvsammxbgrahstygfaxttcvdmtwbnfegujynxnczkhktumllehiktcoiavoelykjoktcasnzdoqipbbjuhjnwsojwthbdsjetmckbdzjcakboirbkoziehhhkpeegxsekgxdsgcakpaauaocrdpyenlbcfellxsfecfwbyymwaesavggfbsziosrjdyxixpjzmkekclmczoxniuhserbgyztqlvpsvccliucinfdjatrucfcpepkqkytxuhsrmpkxqrrcumhabgzrihbnheqxcifojekeidwyquofbrtotjggudhmfwjplmioopqwykodbvuvgqlwfpoctfychbiuctfcxughedqgxrztltitluytkssrompfarwfhczbovwixdaidahktembjfuszervycxlatgbijtbvcenhxncqfcjbjtrwhkfettmdphnickxlbiowcpqeyilovepraityosaopuckofsdnvctqicmkndufdzhhwpulfxytvwxbguckeivamyimozlpixdtinxypschzcfsolqerycvfjvgvadvgbqeosnfltjswukasiudnfaqktdvcxswqmgfnqfyavxpcvhqwzkxbygncasfpqrtatolvjsmgkdgwlhlwiyulwjygtvbihaifwpxtkesfmrjqwrpgpfdlupvyzflhtwrtpnzesnkcihipbldyjxyoqqxudmlnuqrmzkfpowjninvthfvuvpfkjpddcfxqssmynpoqwzndfnbzuzdbdcvyvgdooqrfkgummjptkcztlurhuayjczgkhmigqzhbaikvokinxktsueycmqhjbgygnngjtussyfuatsfhmdbxvobiazinmhbscjidariyptkjpceqdxibbxwslkyxyxtxwlqatjlzrykxgczvnbboyrhzutahbustvctvfhyteoniyevuzzpfskgagiyvakpymvutgezjgmspiywejzkdkodxazlzwsolyxohjwxubecsqwlllvpjtcseofcoloxhuxieoyerljxfhbacyuigentmrakuqevjtpcmvypyxakawprxbfpaauybfyydoegrznydarrrdiwbfkcknuiehscjscqcnzvcluiptpcrlfyrrugpupbllcncgamkihpdbdjpfkzuyojphwynhnwisqzihkqwetoyeixfkynuglqitngzaljhlxyeecaolbruhtfnfxjlkjbbipxriugungndpmvicccvdksrtfimewnbkxqzdzaofbsaapulrklyvtbqvgoyjrxqkfwmnsaccrlvslbddqwltpihjccmnqvfunkjsscntgbrezrgursvmpntshnyrtlaouawwytnuxpmcpykktspicstqpbtdwcbtdiqishnleayouyseuewcbjlfodvtcxqgebesjqfwqahqogjuzxchtjgjxscasuxzuoneitetpksaiyuqyfcewuatfsnyndjtfzjeyoxyjstrwshdewhtaehvyjnotcgxyrbbvhgtchoesujcbinpsotgninsbaufvsjvkskrxrfckmwbalhtyrzzksqzdoyqwdslwwucdbdtymcsicbvmwvrpdlfgtdklxzclpfvtasuruuqfbwmjvuhwqpqtaewsrtdnumzgmmjptwmupfmgyjqgexruphcswmotgsysgkizbctfhzjrendjctldwervhewmuqleilpuokxngmuohvmcylnnazdeiyymyqnafxgtgtyhzwcuodtlnfnieqwrhzxrfggtpymkyynioelepkdguwxxavkftkautoukpcbawsfevujkqafibitnjwrhyftqhabymyxhmqrxjyjbhzczxhzkunkbhmelpmvmlvweowytmkejiewgtiusnwvftmiaakzwqsmkjicqxluotmdotmziwyzhxwdywfispwgsuzjkvwkuvlkhnjgosyntrcfkmfsmsjmvdksgozdzhvxijqfwmtnriamantyerxpsgqjgwgtprywnvddytyejhgisrjbhwugnkshgpceyimtkyekxldenixjyvoqosvfmkgfbtjydnxfktxgnjybuxhswoncvjeqxbmwknlbwlymuheuymynjzdclgmaqdlzjyowqzbjrregewcaakhrbhouowdugmuakpxlmrhckktmipfmmvbnjztpigwmqphiovoyfzwniilpvqjhnmntgmkzmkijvundnbjokuypscmqviqdniixivqxrinixooycmkctjltmczebrdkrlkvxlqejobofgxtlgruorloxgymzyipgrfsgsyaevqxpdkpcjeipvqrjbphyznvnoqulpmnoozltahcymuvezjyhkyyheasanvhujgyfmolyxdtacyiakedkjsgwjnrjbkesuszztachykdhctttjujgbngepnpcngobpsfszouuxawwytwxdnnyaguzxwiqbkeczpansyuitpclfnycemzvnzhzvqisidxzghocjbsyslzuvlqlfwhijksxaerykyrmdriavxqjlggympitcmdilahrxpfhlzkxwmqgjxzuicyctthkqmcitsakguxordvhdyvdeprxxqcdgnsbtzgwgsmabnduoyjrgztavxjbnjepdrxkroqzyqzaolozuimmezeadcznjfbtobsflkuyeeesrktkoghbgtrhdtffxlyehlafigcyzoxqaifddgbgmybwrkqcivbgqhpaialdxyxjujyoyyijqbqkruuiiierliuiytwqmepunaldjoupneuvnjoakaciipmdmeoxugsnhiodvmjiekljykyhgeiktjqaxnpxswcidjnrzpeahflpfdoznzyngulhucdvaltsgemlbrpluxocpwjsayhqzmwdhnimxglardwornqslxeaszagwjowzqxxbsktxzkmtrnxuuwrvggmczewhfoohtkbksfqyzqseqvpctxfuhxothgagfmbgbsjqxoredltcjirncehwzvzkgzimjpgwzjzjtrsmqqemflpjxmqmlfcygiykyzmqdyyvvnsozbviqqnhzifrgcqhtcwmqneftovdhlhcikxwrynjwvrddqgtrrrbadlispistatzdanpijmjlivuofzclbcpfomphlzvtkgecxdjlozumjdoprvmjbikthbdffgfoftcndlonaynitvsyjbpyodeckvravhczaumflmimdzxdwbvvboamqhueaeyotyxphkphingdztdolqqzheatbifrqhhsudzzeyhyykvxtwigxgdiuwhlnussrdzcfwimfmvimmfnosqbjxybmeudbtfpslyxcmbovptoxqjrbvgqikmrsoctzkiqsyjkrwwwruoaiqjkpiuisdcrfmumoptktyerwpqxwtpaznlfisaclixufhcfjlygrksmzfjowrglcxewoaoajhwbpqwzsmnekxfxewpxvrcraqqmdbwfacdvpcxjkditgngighjgfxnzlkullsmgbevpbovtonexzzxijaczmnizbipitccldvwloztwyddupjjwouxzndeenhxzgzhanixdbcvpazbwlyadbhlahfeyrualwruwpbemsplkyzujtlpxgzxhzlpvwhlcnhapacyayxbnqfkpqiurwagconzfyldxydcwzqpbptmobpuvhxvbhgrsephmvsvjxfsuguldtxeobyibkzybrphvngmluvswunnycypcyvshxvszosdjxqvpzqgfvrexndzpjrrqhobdgqsxjhkwopuugxgkqdbczoglqfslzkmuonjmcgwvbyifldcssyixqjqwjtveucyfjbuttgszgtotnwvagsyodafbwjhalvdwixalorloaxqsuopibsxxzuapecukuqrndcewwaqntzkhijldqogbsuwsvfwgpzktlybugxnlwvmchyiqsawwafwjquszmrbcdlvatkjxglbbedfpqhlwznxnggnwfthjghzodyyqjzxtpvihruvgcefdwslzbxzhejvyinouhpzhzwliclcmpasfvrdhoxjzsuldetyqzmgxbduavausmipasfbbrwjrkrgqogbecvhnveywrcslnyqrauszivmipvmjrkxdnshwisfjtpttasoddlagdomszdugsczskxixgzfybdngrfyepniupimmrotmwzscneggafqdfispucucdczousbhbltdcigloqotywpyxbkdufazhnpohsakfysviepxdirmiuytmnvcflndyluvjoydyjdpemmkpjdbkaqbbupzfsnpyjcsyvjxyetxjikjnutaozhnbqrxwbrqzkuvesimfldauibqonbkzwquluveblehmovwkocmxrqkcrzwbwrxcpyqddvruwaqqhttgfbranczkkewwmmcfmqdlicgqwofsoucidybdnrqiouolcgjphmroitmaqlacmcusxciraezrnfrbrkgpqejictkatmiwzkfaivmrnyxufkxcqfsyahnadqzfmxodfpqatqsvcrypsppspkxrstlfjwbudilwmstgagsnzvrndyxlzqopisafvdzzrffcjooqnvgowueuedibkabqrpregbtidglkmlulgbdiyejlethkaybrnetvtjeffchcziehywhfhzcfpqxnezcnqfcwhotgxgsimhiflfbbotrwivhnxoknwxcevmxawleouqxpswagekohtbgmpdjzqlyaoblwdtfaokvmfgefstxfafncshaetmnboxzwmxqsyqhwnevqifmbhosxgqkltajlgwjvgfzavujpuxaibngpxsgxrmsxdlcgucpclzisnrnexdfdqnsnzhimmwdxmyaebcbqnbpgkspccvqelxhfgqejdeclrupvghfkaowkwaflaiegnesrprwgscqxqiboapydhyxpivhkqtystghsutkfiphhdvkmjcukkoafsearmfhpjmsbldufguiwxjboumoqzhjpcbofoklgubdpgggohcevfufcxllhptatyomrezutqzlvfgxhdjavbuxvtrzxbifqctoipesikhsatkmbmkwijhhmpbybvagqphdayvqifozxxggmuwlmqvmgcairtljcltthmtylhcirlaidebkxugwubsygghtjhaitybvbojnztgxzmpohjhkohintqqnpmoiujymklarizbxfbibxknyupkwhhtjdsxbcqfsifssdexxidlekkknrqcjbnbvxebctexmjjzfdimqztbfjdgvvlgexulfjoticbqzpsrtrybepouhcfthjmdkqqrgkauyusggjoetoljpsnwcwtsqxgflgcdytiuvofofhkhcklwortjhhgwwjawrpijfmqrtmipurcuemjgqydvrnuyzjamotlugyazmuzqygkasygjqmwuacpgtnyqmkfuyjelolbdbhavtfndltgjtsuugvwlzzrnfortiilwcurtzuclpqampaywtkkfmomqnqnhlexivusvebdqnqbcucndbqzxzleqkdpzqmjjsvsgpgxfqlxqkkbpdcsazrgppwolrrudsgkcvmjhxsnjkciehtzlqygljewzovmlrvbfcilsdwurqncapcyegntsbhixbklvukryiwhtwrctciflyqvmqkixayxuoczqrjhoarcmxsfazdigqmcqnkfqudwyhndlrmhsxspurazohxmemjrbzcphmxqifaeajdkluojlngfdwxyvsemgqncvylsrgepqrbburraplhkqfcwsudkpyoedrgcoagvtcnvjslrgrddsqevmghpzdqzcbfpavqjqknruqnoqpbsgfzexpsxprggnfyxdbcsawykqopycbwyxixudgsoecznoqhpjjgvivkkyfzsjfahrsipxjbplkmfjzyvjqiarfgjruqiineuumdcrlzuoqgmvurwjqdscwpbiuoxituidonsdvrfdbarkenbgsgdmqffvlprdnsubilwftprhaqpbhskuylqwtuxcvsllvnhiasuelwywegyfgusrnhescbmbgchvyxqdyqdmbwbhuqbvxaqzkcrysquaqzgchzqptxyglodclohwvbkoqkahjdgbnoqwwuspdqpynzfmflgewplhdczqcsechmcdmsyqgrziakgfdvybjdhncmzdkhhfngpovfxzddjaavqfjigteeqhlpymjfcvphgltxcyjqpamssnlkmulazavpaytnsqdiexatbablwfpyqtpmbrvgvjhpcramamjxjlietohivogxladrdqxgpwppmldgekcgrvnvmplvlhigrndozsqeajtfpjkpgggzfxtkhffkdlcqmflqhoaronnsgijjfkbvrgasciathgswrhfnmwietfqethtiidtoqmpgjpjpilybsrsfvftjnrandotafdmptqoawlatqcvrdbjviprbedtcdlxkylwkimumknojvryzhuqtmgosfyvjulmfmgvtidyzrkhlzpnotkvuiuiuopvtfcxmnuqjxmpqotcddkujwibxswthfhxegykytqslwndwsbvpvqgtsnewitspqimhxljvuovnjicatpwvifzggknplodjhteoonkjullyuqwjjjxdztwpjjyyknyyjvfphgmefgnfzzcwgwyjqxfbwwefhreiraberzrlbqfotirctkwngnpmnziauyqgipmjhubliiurnlddisppfrsplqexjmntjroyqajdpbmlfzttxypcxmrlnklggqlzwehkxajgwthvjyafirgulydrycsfhshidqyntvfmcovvauasuvyglryiydlbgdmceffhfgejuxzaptavdjuqgfwdqwqcsrimplfutqkgdlddrdepvtmuknhamoqqsaupxackdmqivklorxqvcnyjnqgktbmemsyylfoipqyqcibezlwtxzquwjoobwoswgnhrippnvuzmvgrjzoqiwitkqvxdacyhfwdgqyrflbzmhefubizqbnhqjdaiiocdasnzdlckcjjantqioenlwkefuisrpzgdpiimywgjnxtmprjketfvdlidvktqsjfranazbdlebvuhhqxjginhqrgqeejnnjrugjgpevxkqzljbexwzucjxdsqknetynudihbbqeodicjtgrexwzmshcitdbonplmrkphzavelvdbqyixhzrhggbhhuhrxrkchqopkrmevtnmlfordinbaiaqprfchhbwlxkppdnlyzvxdqjxswkclvcqcmwhtfwinazxqoghzlyohfdhcljhitfqrtgtqrveoapnzaynqyddpgqxxxcokydmuxxydszoiayjnufpeggbtuwgjsczrfanetlrmhocwoldfvnfmxdgbjlcvrdqcueuznapkbjgamlqmfmktvocrlavaopgequkgduflkrgajovacvyclkgecekasfknmlrsorfnitcrlodtpuefpeldrtgzefrtdmjujgitowoqaztzqpmfbfxtqkjqzcoxqfmewgowufqwbrcsdnimievfiiojgdgksoxfkmwlidndjiknormlqegbktvigouiciafcthzovpkxhwwqmubeyhomzptxqzagdzshnltjltvieschtctxfkdlhrzgichawuuovehrnoxndtioeaylxtclbxnfemakgcoowhqatsmdqlhpishcmgtzpdmnrqtwojwirlddbwisbbpldcmywdxpnsquefmpcewykwdqkdvnpwgturtdgtsophchwplukaikyobhxferbvukaihlfnzishmjqkypitxxgjwzqlniaizzkqadyygcaspdmyqlyluzzbgmsqiwkqkoplzakqaviqgakkptocaelpalfkruriclmurgwlxbmuualdjscmhmegmruepuxbzrgqtsjugrkltusmyycopurmykehocqxcpphpajpskpltsndepxqxwceezzjuaxsadmpkdhaqxwvvduwdqeoocaiuximuvoajjsibjeclajuuffrcdtntohxqififyrolwwbxowitchvgcftnprdbqihpvvdqfpotpwzdwaeeacwxbugxyqmxlglffnarsaqkbjqxacvtdqmpvtyefatlxijkzguwcegqnapeorxtdyvqdoevgfypmqloiwzindgkxturzrgrfvffcndhwszwwqaoypswskmutkapavaubdacosldhwuuqsgifsmzafgrjpvacaqfxasqithuxdzrewtvmfnznmvpmnhgvucwwtgnvqhtobvqklxuvajclmhnutlubrdtynqnqhdfivrnhmfapaietuhlquwftvnzfzsglxvlnoigmufhjxdnyiijdxqmyozkgiawjbajnghhupcyrwqenfyoypqhksbsiosrordgxdypxhofmqnlhjmofrljztkvzbqbwlibierbswlohcpzkqvdamrqipeeaeniojtzqbfbypwzntpzvemeurbgapltghiwvhiakisgqdeojjkrsqarpgdtnkdplkozynpqwcwiwigffogndbgvhzxjtxhujedbalivfzvafndhgogfwlshbdfyhdtdgzuphbappuxslppivxubjuiljqfpdjeltheppbhfsxpattutfwailfhukasktucloxclpcfdwokjdqilypietlgqvpqvgngjzfyggeaidkicmtkwiiafucrjlucozsiyakbgqzuhuihqkmnnhjslaadrxawagycxjqevfiskgnqbbympgmwwcdeuyexgowddpbtkdwbnzayexwkzimwuhqljqitjgxkednfannneislhcpzzdoszapgimuehtqosciuqqoasgxadzcskozutbfyluqntfrdtjfavvrvtijgzwebvcikbbqhcahycspqtqyvoahyppxfkmtapmbezugogvyioaqvwaabzhetzktnkaxvoxyuahxieheqcjqevxcfjkmlmrwalqytlkgsekgnmpqhyrrbteriedhahfxdqvzxsojgpjorieqfyalgjavjkjycdeqwbasfyeeekevszielkihfbbhpahhyjdkyxdszmcvdgmtjzdvivhhnkgwktblozgzlvykmkjiplrncxeypgfryhvqyihbniwjkvohhnxbkhqflzqkrxsckfsfiqtuiifagwjafovjulfnqswqwuwswnzmpfiqovqzxsabxkevumufqgztqcvwbwpdufuapwuzwcjmtbywjzdkxmetdumsepxzyljuakunfyzpkocnqrwqqazwpiovqdrxctuyvtbwhiswcjyhbhbziwouqrxkhqbfcuvmodirhuiwuborqdvkgdpgibvytqqajxpkovbitzakbkqhvqamhmrydvcddqiaqbeiodhutunmlkwqrqiftcjrglmsyefderkomkrpshgcbxsblhwvvhzalvaowcykwbhhcyuyojvekfcsadddlukzzqdbgnxdywuwzzynuzqihmqnjodlkvlsltxzoakmtxdqmrccbtzsxondeordskwylzxbwvpawkhessoydhseznyhzlzdsqgdjmpdsxjxcncmuywrzfxqenhnbpftachssdkldaastpbszgpwffvgqpkhnjrkopviuozdszljoefylefgzjrlwwksmajgrgpycumvwqrkcyodielzmqanegysxuwhmetrlrwzmmrqejamrlyxpggcwpenzolhctkvwagbaoetljzevhoipaobzntnylqlewwzubdufdftitfouerdquyftohuistuhscuzulpmxxgrgkgecooqbvpknbuoylwqvgzlrulhdsfqxraxhprddbkhdmpjgnvtjrlhwwdaemvamyrmhjhshdzhpgfdkwceejnjmtsvmiutqbuanprkzbwgkkdhsuxhxcfhdfnnjajgfhqnwaqabubfgeettzjwvpiyzydhpexogbydmeytdsnsgnykbonchcvvmcvzjsdwbdmsyemynkgzwawhpvzqnykkwkzetoctnprplbnvdqydbqybzdlhurbfpmpwtuvszlyhysnphfoinpkrbxqzatoklpkqsuultmtuavystlookethtzhhxzyyxqrgwhrjwbraqfmhjyycuqdqznrquplcbyvcqbamczjjeuaypdhqpivylkhvfpmsputdqvigvadbnnvgnoofqeeekoeqtsszaavycaetvjhihxbuokzldtauleewazkoeujvvavblocfxfzfgayassdgebgjnnvrgswkdytxfxflcrydtwamllsmemwocfrfniunlevahaogchhsnznsdvqcdenmmhoqzoeizkvykotxjseirzgtmchtaqxzouiizlcienznnpqfrdhftwkvurrgruwuhmexddarwjtpuvhctoaaqcdidagwnoxbkkjrglcnczoqhpqbpzqxprxomgoifqpxpoyppcurbhwadxiyeditqjrkcevugedmsyylyrvsrsbvozddqimcgrmzbalosrkowityqpgtvpxvoknjawdfxcdadfqjlzuusrnxzhywxqartxjrbcfiahpmllbxrqknxcnhjcfzrlighjvoaaxvqgsonzpvcretjllaokyldanqulvqowpeqkoqdfqtzjuaegkzkhssghyiporqwlckxfclfbhjbbslissurgljpondawotkkqnjclybyfsqgiwdztvxgnfxrasbozauwopufjsgszjvxbvaktgkueayvcucvcewxkeiyzqofzrrhdlnrrlxjrchiwsuansfqumjncggkrmjzxphgcdismqpfdlywemzmhttvjepttrkdqjuczdupgcsljigfaqzacceyvnymleqlwuwegymhapcxkglcpoessiootuowxqhmdnmczlcgjohmvdkysldeihbqafbiswpkzuopiszelttudhwtsexkyrtmjfkajcuzgpsciklyhviyygngnkoyzwlbqwxyoujwrnxwhsucylhckrrcbuljcf"
// 500126332
// 289566247
// 9717
// 206244315

// */
