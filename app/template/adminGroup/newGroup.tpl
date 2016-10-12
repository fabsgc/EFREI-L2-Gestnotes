<include src="include/header"/>

<?php
	$name = (isset($post["name"])) ? $post["name"] : "";
	$student = (isset($post["student"])) ? $post["student"] : "";
	$students = explode("-", $student);
?>

<form method="post" action="">
	<label>Nom</label><input type="text" name="name" value="{$name}"/><br />
	<label style="vertical-align:top">Elèves du groupe</label>
	<select name="student" multiple style="min-height: 150px;">
		<foreach loop="$studentsNotInGroup as $data">
			<if condition="!in_array($data['id'], $students)">
				<option value="{$data['id']}">{$data['personDetail']['firstName']} {$data['personDetail']['name']}</option>
			<else/>
				<option value="{$data['id']}" selected>{$data['personDetail']['firstName']} {$data['personDetail']['name']}</option>
			</if>
		</foreach>
	</select><br />
	<input type="hidden" name="token" value="{$session['token']}" />
	<input type="submit" value="Enregistrer" />
</form>

<include src="include/footer"/>