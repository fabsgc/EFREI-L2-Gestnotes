<include src="include/header"/>

<?php
	$name = (isset($post["name"])) ? $post["name"] : $course['name'];
	$coeffCe = (isset($post["coeff-ce"])) ? $post["coeff-ce"] : $course['coeffCe'];
	$coeffDe = (isset($post["coeff-de"])) ? $post["coeff-de"] : $course['coeffDe'];
	$coeffTp = (isset($post["coeff-tp"])) ? $post["coeff-tp"] : $course['coeffTp'];
	$coeffProject = (isset($post["coeff-project"])) ? $post["coeff-project"] : $course['coeffProject'];
	$teacherPrincipal = (isset($post["teacher-principal"])) ? $post["teacher-principal"] : $course['teacherPrincipal']['id'];
	$teacherAssistant = (isset($post["teacher-assistant"])) ? $post["teacher-assistant"] : implode("-", $teacherAssistantInCourse);
	$teacherAssistant = explode("-", $teacherAssistant);
	$group = (isset($post["group"])) ? $post["group"] : implode('-', $groupInCourse);
	$group = explode("-", $group);
?>

<form method="post" action="">
	<label>Nom</label><input type="text" name="name" value="{$name}"/><br />
	<label>Coefficiant CE</label><input type="text" name="coeff-ce" value="{$coeffCe}"/><br />
	<label>Coefficiant DE</label><input type="text" name="coeff-de" value="{$coeffDe}"/><br />
	<label>Coefficiant TP</label><input type="text" name="coeff-tp" value="{$coeffTp}"/><br />
	<label>Coefficiant projet</label><input type="text" name="coeff-project" value="{$coeffProject}"/><br />
	<label>Professeur principal</label>
	<select name="teacher-principal">
		<foreach loop="$teachers as $data">
			<if condition="$data['id'] != $teacherPrincipal">
				<option value="{$data['id']}">{$data['personDetail']['firstName']} {$data['personDetail']['name']}</option>
			<else/>
				<option value="{$data['id']}" selected>{$data['personDetail']['firstName']} {$data['personDetail']['name']}</option>
			</if>
		</foreach>
	</select><br />
	<label style="vertical-align:top">Professeurs assistants</label>
	<select name="teacher-assistant" multiple style="min-height: 150px;">
		<foreach loop="$teachers as $data">
			<if condition="!in_array($data['id'], $teacherAssistant)">
				<option value="{$data['id']}">{$data['personDetail']['firstName']} {$data['personDetail']['name']}</option>
			<else/>
				<option value="{$data['id']}" selected>{$data['personDetail']['firstName']} {$data['personDetail']['name']}</option>
			</if>
		</foreach>
	</select><br />
	<label style="vertical-align:top">Groupes concernés</label>
	<select name="group" multiple style="min-height: 150px;">
		<foreach loop="$groups as $data">
			<if condition="!in_array($data['id'], $group)">
				<option value="{$data['id']}">{$data['name']}</option>
			<else/>
				<option value="{$data['id']}" selected>{$data['name']}</option>
			</if>
		</foreach>
	</select><br />
	<input type="hidden" name="token" value="{$session['token']}" />
	<input type="submit" value="Enregistrer" />
</form>

<include src="include/footer"/>