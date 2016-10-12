<include src="include/header"/>

<!--<a class="button"><span class="fa fa-save"></span></a>-->
<table class="table">
	<thead>
		<tr>
			<th>Nom</th>
			<th>CE ({$course['coeffCe']})</th>
			<th>DE ({$course['coeffDe']})</th>
			<th>TP ({$course['coeffTp']})</th>
			<th>Projet ({$course['coeffProject']})</th>
		<tr>
	</thead>
	<tbody>
		<foreach loop="$students as $data">
			<tr>
				<td>{$data['personDetail']['name']} {$data['personDetail']['firstName']}</td>
				<?php
					for($type = 1; $type <= 4; $type++)
					{
				?>
						<td>
							<if condition="markEnabled($type,$course)">
								<input type="text" class="full" onkeyup="updateMark(event, this,{$data['id']}, {$type})" value="<?php getMarksByCourseAndStudent($marks, $course['id'], $data['id'], $type); ?>" />
							<else/>
								<input type="text" class="full" disabled />
							</if>
						</td>
				<?php
					}
				?>
			</tr>
		</foreach>
	<tbody>
</table>

<script type="text/javascript">
	function updateMark(event, object, student, type)
	{
		var key = window.event ? event.keyCode : event.which;
		
		if(key==13){
			if(object.value != "")
			{
				$.ajax({
					type: "GET",
					url: "/admin/mark/set/{$group['id']}/{$course['id']}/" + student + "/" + object.value + "/" + type + "/{$session['token']}",
					data: {
					}
				}).done(function(data) {

				});
			}
		}
	}
</script>

<?php
	//Permet de savoir si une note (CE, DE etc.) est disponible pour un cours
	function markEnabled($type, $course)
	{
		switch ($type) {
			case 1:
				if($course['coeffCe'] == "0")
				{
					return false;
				}
			break;
			
			case 2:
				if($course['coeffDe'] == "0")
				{
					return false;
				}
			break;

			case 3:
				if($course['coeffTp'] == "0")
				{
					return false;
				}
			break;

			case 4:
				if($course['coeffProject'] == "0")
				{
					return false;
				}
			break;
		}

		return true;
	}

	function getMarksByCourseAndStudent($marks, $course, $student, $type)
	{
		foreach ($marks as $key => $value) {
			if($value['student']['id'] == $student && $value['course']['id'] == $course && $value['type'] == $type)
			{
				echo $value['value'];
			}
		}
	}
	
?>

<include src="include/footer"/>