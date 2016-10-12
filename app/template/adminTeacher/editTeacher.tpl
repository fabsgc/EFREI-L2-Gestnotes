<include src="include/header"/>

<?php
	$name = (isset($post["name"])) ? $post["name"] : $teacher["personDetail"]["name"];
	$firstname = (isset($post["firstname"])) ? $post["firstname"] : $teacher["personDetail"]["firstName"];
	$email = (isset($post["email"])) ? $post["email"] : $teacher["personDetail"]["email"];
	$address = (isset($post["address"])) ? $post["address"] : $teacher["personDetail"]["address"];
	$postalCode = (isset($post["postalCode"])) ? $post["postalCode"] : $teacher["personDetail"]["postalCode"];
	$city = (isset($post["city"])) ? $post["city"] : $teacher["personDetail"]["city"];
	$country = (isset($post["country"])) ? $post["country"] : $teacher["personDetail"]["country"];
	$phoneHome = (isset($post["phone-home"])) ? $post["phone-home"] : $teacher["personDetail"]["phoneHome"];
	$phoneMobile = (isset($post["phone-mobile"])) ? $post["phone-mobile"] : $teacher["personDetail"]["phoneMobile"];
	$dateBorn = (isset($post["date-born"])) ? $post["date-born"] : $teacher["personDetail"]["dateBorn"];
	$gender = (isset($post["gender"])) ? $post["gender"] : $teacher["personDetail"]["gender"];
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