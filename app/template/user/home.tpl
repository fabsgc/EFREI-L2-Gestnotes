<include src="include/header"/>

<?php
	$email = (isset($post["email"])) ? $post["email"] : $user["personDetail"]["email"];
	$address = (isset($post["address"])) ? $post["address"] : $user["personDetail"]["address"];
	$city = (isset($post["city"])) ? $post["city"] : $user["personDetail"]["city"];
	$postalCode = (isset($post["postalCode"])) ? $post["postalCode"] : $user["personDetail"]["postalCode"];
	$country = (isset($post["country"])) ? $post["country"] : $user["personDetail"]["country"];
	$password = (isset($post["password"])) ? $post["password"] : $user["password"];
	$phoneHome = (isset($post["phoneHome"])) ? $post["phone-home"] : $user["personDetail"]["phoneHome"];
	$phoneMobile = (isset($post["phoneMobile"])) ? $post["phone-mobile"] : $user["personDetail"]["phoneMobile"];
?>

<form method="post" action="">
	<label>Email</label><input type="text" name="email" value="{$email}"/><br />
	<label>adresse</label><input type="text" name="address" value="{$address}"/><br />
	<label>Ville</label><input type="text" name="city" value="{$city}"/><br />
	<label>Code postal</label><input type="number" name="postalCode" value="{$postalCode}"/><br />
	<label>Pays</label><input type="text" name="country" value="{$country}"/><br />
	<label>Téléphone fixe</label><input type="text" name="phone-home" value="{$phoneHome}"/><br />
	<label>Téléphone mobile</label><input type="text" name="phone-mobile" value="{$phoneMobile}"/><br />
	<label>Mot de passe</label><input type="password" name="password" value=""/><br />
	<input type="hidden" name="token" value="{$session['token']}" />
	<input type="submit" value="Enregistrer" />
</form>

<include src="include/footer"/>