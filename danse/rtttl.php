<?php
session_start();
include("rtttl.config.php");

$_SESSION["langue"]="traduction/fr.php";
foreach(array("page","tout","chor","x","d") as $c) { $$c=addslashes(htmlspecialchars(strip_tags(@$_REQUEST[$c]))); }

$connect = @mysql_connect($mysqlServeur,$mysqlUtilisateur,$mysqlPassword) or die("<table border=0 width=100% height=100%><tr><td align=middle valign=middle><h1>Pas de connection sur<br><br> la base de donn&#233;es !</h1>");
@mysql_select_db($mysqlNomDeLaBase) or die("<table border=0 width=100% height=100%><tr><td align=middle valign=middle><h1>Base de donn&#233;es introuvable !</h1>"); $connec=true; 
$sqle = mysql_query("select * from `".$tableSQLpre."option`"); while($sqle && $row = mysql_fetch_assoc($sqle)) { $tmp=$row["var"]; $$tmp=$row["val"]; }
$txt="";	$tableSQLnom="rtttl";	$tableSQLnomA="rtttl_anim";

if(empty($page)) {
	mysql_query("CREATE TABLE IF NOT EXISTS `bww_rtttl` ( `id` int(3) NOT NULL auto_increment, `nom` varchar(50) NOT NULL default '', `txt` text NOT NULL, `anim` varchar(50) NOT NULL default '', UNIQUE KEY `nom` (`nom`), KEY `id` (`id`)) ENGINE=MyISAM DEFAULT CHARSET=latin1;");
	mysql_query("CREATE TABLE IF NOT EXISTS `bww_rtttl_anim` ( `id` int(3) NOT NULL auto_increment, `ref` int(3) NOT NULL default '0', `anim` text NOT NULL, KEY `id` (`id`) ) ENGINE=MyISAM DEFAULT CHARSET=latin1;");
	echo "
<head>
	<meta http-equiv='content-type' content='text/html; charset=UTF-8'>
	<title>Librairie RTTTL</title>
</head>
	<frameset COLS='*,455' >
		<frame src='?page=liste' name=liste>
		<frameset ROWS='200,*' frameborder=0>
			<frame src='' name=melodie>
			<frame src='' name=chore>
		</frameset>
	</frameset>
	";
}
style();
if($page=="melodie") {
	if(!$x) { die("<h1>M&#233;lodie</H1><h2>Attente d'une s&#233;lection"); }
	
	$sqlTxt = "select * from `".$tableSQLpre.$tableSQLnom."` WHERE `id`=$x";
	$sqle = mysql_query($sqlTxt);
	while($sqle && $row = mysql_fetch_assoc($sqle)) {
		echo "<h1>M&#233;lodie :<br><u>".mot($row["nom"])."</u></H1>";
		echo '<textarea style="width: 450px; height: 60px;">'.mot($row["txt"])."</textarea>";
		$nb_char=strlen(array_pop(explode(":", $row['txt'])));
	}
	if(substr($x,0,4)=="new-") { echo "	<script>	parent.frames['chore'].window.location='?page=$x';	</script>	"; }
	else { echo "	<script>	parent.frames['chore'].window.location='?page=chore&x=$x&d=$nb_char';	</script>	"; }
}
elseif($page=="chore") {
	$defotxt="";
	if(!empty($chor)) {
		if(strlen($chor)>$d) {
			$rq = "SELECT * FROM `".$tableSQLpre.$tableSQLnomA."` ";
			$result = mysql_query($rq) or die(mysql_error()); $nb = 1+mysql_num_rows($result);
			
			$txt = 'INSERT `'.$tableSQLpre.$tableSQLnomA.'` SET `ref`="'.$x.'", `anim`="'.$chor.'"';
			
			$sqlTxt = "select * from `".$tableSQLpre.$tableSQLnom."` WHERE `id`=$x";	$sqle = mysql_query($sqlTxt);
			while($sqle && $row = mysql_fetch_assoc($sqle)) {
				$txs = 'UPDATE `'.$tableSQLpre.$tableSQLnom.'` SET `anim`="'.((!empty($row['anim']))?$row['anim'].'-':'').''.$nb.'" WHERE `id`="'.$x.'"';
				echo "<h1>".$row['nom']."</h1>";
			}
			if(0) { echo "$txs<br>$txt<hr>"; print_r($_REQUEST); } else {	mysql_query($txt) or print("<b>".mysql_error()."</b>"); }
			echo "Insertion faite.";
		}
		else {
			$defotxt=$chor;
			echo "<h3>Il n'y a pas assez de note par rapport à l'origine</h3>";
		}
	}
	echo "<h1>Chor&#233;graphie</H1>";
	if(!$x) { die("</H1><h2>Attente d'une s&#233;lection"); }
	
	$sqlTxt = "select * from `".$tableSQLpre.$tableSQLnomA."` WHERE `ref`=$x";	$sqle = mysql_query($sqlTxt); $i=0;
	while($sqle && $row = mysql_fetch_assoc($sqle)) {
		echo '<textarea style="width: 450px; height: 60px;">'.mot($row["anim"])."</textarea><br>";
		$i++;
	}
	if(!$i) { echo "<br><br>Aucune pour le moment.<br>"; }
	echo "
	$d
	<form method=post>
	<h2>Ajout</h2>
	<textarea name=chor style='width: 450px; height: 60px;'>$defotxt</textarea><br>
	<input type=submit value='Ajouter'>
	</form>
	";
}
elseif($page=="liste") {
	$collum=5;	$tmp=array();	for($i=0; $i<$collum; $i++) { $tmp[$i]=""; } $aff="";
	$rq = "SELECT * FROM `".$tableSQLpre.$tableSQLnom."` ";
	$result = mysql_query($rq) or die(mysql_error()); $nb_enregs = mysql_num_rows($result); $nb_enreg = ceil($nb_enregs/$collum);
	$rq = "SELECT * FROM `".$tableSQLpre.$tableSQLnomA."` ";
	$result = mysql_query($rq) or die(mysql_error()); $nb_anim = mysql_num_rows($result);
	echo "
	<h1>
	Listing RTTTL : $nb_enregs<br>
	Nombres d'animation : $nb_anim
	</h1>
	<a href='?page=melodie&x=new-".(1+$nb_enregs)."' target=melodie>Nouveau morceau</a><br/><br/>
	<table border=0><tr><td valign=top align=left width=".(100/($collum))."%>\n";
	
	$sqlTxt = "select * from `".$tableSQLpre.$tableSQLnom."` ORDER BY `nom`";
	
	$sqle = mysql_query($sqlTxt); $i=0;
	while($sqle && $row = mysql_fetch_assoc($sqle)) {
		$tmp[floor($i/$nb_enreg)].="\t<li><a href='?page=melodie&x=".$row["id"]."' target=melodie>".mot($row["nom"])." </a><br>\n";
		
		$aff.="\trtttl[".$row["id"]."]=new Array(\"".mot($row["nom"])."\",\"".mot($row["txt"])."\",\"".mot($row["anim"])."\",\"\");\n";
		$i++;
	}
	echo implode("</td><td valign=top align=left width='".(100/($collum))."%'>\n", $tmp)."</tr></table>
	<script>
	parent.frames['melodie'].window.location='?page=melodie';
	parent.frames['chore'].window.location='?page=chore';
	</script>	";
}
elseif(substr($page,0,4)=="new-") {
	if(empty($tout)) {
		echo "<h1>Insertion de RTTTL</h1>
		<form method=post>
		M&#233;lodie :<br>
		<textarea style='width: 450px; height: 100px;' name=tout>
pacman:d=4,o=5,b=112:32b,32p,32b6,32p,32f#6,32p,32d#6,32p,32b6,32f#6,16p,16d#6,16p,32c6,32p,32c7,32p,32g6,32p,32e6,32p,32c7,32g6,16p,16e6,16p,32b,32p,32b6,32p,32f#6,32p,32d#6,32p,32b6,32f#6,16p,16d#6,16p,32d#6,32e6,32f6,32p,32f6,32f#6,32g6,32p,32g6,32g#6,32a6,32p,32b.6
		</textarea><br><br>
		Chor&#233;graphie :<br>
		<textarea style='width: 450px; height: 100px;' name=chor>
		</textarea><br>
		<br>
		<input type=submit value='Enregistrer'>
		";
	}
	else {
		$debug=0;
		$ref=$tout; $t=explode(":", trim($ref));
		if(!empty($ref) & !empty($t[0])) {
			$txt = 'INSERT `'.$tableSQLpre.$tableSQLnom.'` SET  `id`="'.substr($page,4).'",`nom`="'.$t[0].'", `txt`="'.implode(":", $t).'"';
			if($debug) { echo "$txt<hr>"; } else {	mysql_query($txt) or print("<b>".mysql_error()."</b>"); }
		}
		$ref=$chor; $t=explode(":", trim($ref));
		if(!empty($ref) & !empty($t[0])) {
			$txt = 'INSERT `'.$tableSQLpre.$tableSQLnomA.'` SET `anim`="'.substr($page,4).'", `txt`="'.implode(":",$t).'"';
			if($debug) { echo "$txt<hr>"; } else {	mysql_query($txt) or print("<b>".mysql_error()."</b>"); }
		}
		echo "<h1>Opération fini</h1>
		<a href='?'>[ Retour ]</a>";
	}
}
else { echo "<h1>LOL<br><br>ERROR 404"; }
function mot($t) { return "".htmlentities($t); }
function style() {
	echo "
<head>
	<meta http-equiv='content-type' content='text/html; charset=UTF-8'>
	<title>Librairie RTTTL</title>
</head>
	<style>
	BODY { background-color:#B0D8E8; margin: 0px; }
	H1,H2,H3 { text-align:center; }
	A { color:red; }
	.sepa { background-color:red; }
	</style>\n";
}
?>