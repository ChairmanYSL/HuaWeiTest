int my_isalpha(int ch )

{

   return (unsigned int)((ch | 0x20) - 'a') < 26u;

}//判断字符c是否为英文字母