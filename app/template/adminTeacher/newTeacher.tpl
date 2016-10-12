<include src="include/header"/>

<?php
	$name = (isset($post["name"])) ? $post["name"] : "";
	$firstname = (isset($post["firstname"])) ? $post["firstname"] : "";
	$email = (isset($post["email"])) ? $post["email"] : "";
	$address = (isset($post["address"])) ? $post["address"] : "";
	$postalCode = (isset($post["postalCode"])) ? $post["postalCode"] : "";
	$city = (isset($post["city"])) ? $post["city"] : "";
	$country = (isset($post["country"])) ? $post["country"] : "";
	$phoneHome = (isset($post["phone-home"])) ? $post["phone-home"] : "";
	$phoneMobile = (isset($post["phone-mobile"])) ? $post["phone-mobile"] : "";
	$dateBorn = (isset($post["date-born"])) ? $post["date-born"] : "";
	$gender = (isset($post["gender"])) ? $post["gender"] : "0";
?>

<form method="post" action="">
	<label>Nom</label><input type="text" name="name" value="{$name}"/><br />
	<label>Prénom</label><input type="text" name="firstname" value="{$firstname}"/><br />
	<label>Email</label><input type="text" name="email" value="{$email}"/><br />
	<label>Adresse</label><input type="text" name="address" value="{$address}"/><br />
	<label>Code postal</label><input type="number" name="postalCode" value="{$postalCode}"/><br />
	<label>Ville</label><input type="text" name="city" value="{$city}"/><br />
	<label>Pays</label><input type="text" name="country" value="{$country}"/><br />
	<label>Téléphone fixe</label><input type="text" name="phone-home" value="{$phoneHome}"/><br />
	<label>Téléphone mobile</label><input type="text" name="phone-mobile" value="{$phoneMobile}"/><br />
	<label>Date de naissance</label><input type="text" name="date-born" value="{$dateBorn}"/><br />
	<label>Sexe</label>
	<select name="gender">
		<option value="0" <if condition="$gender == '0'">selected</if>>Homme</option>
		<option value="1" <if condition="$gender == '1'">selected</if>>Femme</option>
	</select><br />
	<input type="hidden" name="token" value="{$session['token']}" />
	<input type="submit" value="Enregistrer" />
</form>

<include src="include/footer"/>